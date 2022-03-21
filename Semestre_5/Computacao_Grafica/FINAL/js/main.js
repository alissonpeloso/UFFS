//Aluno: Alisson Luan de Lima Peloso
import { Element } from "./class/element.js";
import { Character } from "./class/character.js";
import { Light } from "./class/light.js"
import { Sky } from "./threejs/Sky.js"
import { PointerLockControls } from './threejs/PointerLockControls.js';
import { OrbitControls } from './threejs/OrbitControls.js';
import * as THREE from './threejs/three.module.js';
import * as Util from './util/inits.js';

var scene, camFPS, renderer, camTPS, activeCam, controlFPS, controlTPS;
var elements = new Object();
var lights = new Object();
var clock = new THREE.Clock();
var ground;
var sky;
var sun;
var sunPostition;
let sunAnchor = new THREE.Group();
var char = new Array();
var charBox;
var currentChar = -1;
var keyPressed = [];
var listener;
var soundBack = [];

var onKeyUp = function (e){
    if(e.keyCode == 80){
        keyPressed['p'] = false;
    }
    if(e.keyCode == 87){
        keyPressed['w'] = false;
        char[currentChar].Animation.changeAnimation(0);
    }
    if(e.keyCode == 83){
        keyPressed['s'] = false;
        char[currentChar].Animation.changeAnimation(0);
    }
    if(e.keyCode == 65){
        keyPressed['a'] = false;
        char[currentChar].Animation.changeAnimation(0);
    }
    if(e.keyCode == 68){
        keyPressed['d'] = false;
        char[currentChar].Animation.changeAnimation(0);
    }
    if(e.keyCode == 67){
        keyPressed['c'] = false;
    }
    if(e.keyCode == 32){
        keyPressed['spacebar'] = false;
    }
}

var onKeyDown = function (e){
    if(e.keyCode == 80){
        keyPressed['p'] = true;
        changeCam();
    }
    if(e.keyCode == 87){
        keyPressed['w'] = true;
        char[currentChar].Animation.changeAnimation(1);
    }
    if(e.keyCode == 83){
        keyPressed['s'] = true;
        char[currentChar].Animation.changeAnimation(1);
    }
    if(e.keyCode == 65){
        keyPressed['a'] = true;
        char[currentChar].Animation.changeAnimation(1);
    }
    if(e.keyCode == 68){
        keyPressed['d'] = true;
        char[currentChar].Animation.changeAnimation(1);
    }
    if(e.keyCode == 67){
        keyPressed['c'] = true;
        changeChar();
    }
    if(e.keyCode == 32){
        keyPressed['spacebar'] = true;
    }
}

function initSky() {
    sky = new Sky();
    sky.scale.setScalar( 450000 );
    scene.add( sky );

    sun = new THREE.Vector3();

    const uniforms = sky.material.uniforms;
    uniforms[ 'turbidity' ].value = 1.5;
    uniforms[ 'rayleigh' ].value = 1.5;
    uniforms[ 'mieCoefficient' ].value = 0.01;
    uniforms[ 'mieDirectionalG' ].value = 0.7;

    sun.setFromSphericalCoords( 1000, 0, 0 );

    uniforms[ 'sunPosition' ].value.copy( sun );

    sunPostition = uniforms['sunPosition'];

    renderer.toneMappingExposure = renderer.toneMappingExposure;
    renderer.render( scene, camFPS );
}

var loadElements = function (scene) {
    return new Promise(async (resolve, reject) => {
        if(Object.keys(elements).length > 0){
            for await (let element of Object.keys(elements)) {
                await elements[element].load(scene);
                if (elements[element].constructor.name == "Character") {
                    char.push(elements[element]);
                }
            }
            resolve(true);
        }
    })
}

var sunAnimation = function (){
    sunAnchor.rotation.x+= 0.0003;
    if(sunAnchor.rotation.x >= Math.PI*2){
        sunAnchor.rotation.x = 0;
    }

    if (sunAnchor.rotation.x >= Math.PI / 2 && sunAnchor.rotation.x <= Math.PI * 1.5) {
        lights['pointLight1'].mesh.visible = true;
        lights['pointLight2'].mesh.visible = true;
    } else {
        lights['pointLight1'].mesh.visible = false;
        lights['pointLight2'].mesh.visible = false;
    }

    sun.setFromSphericalCoords( 1000, sunAnchor.rotation.x , 0 );

    sunPostition.value.copy(sun);
}


var changeCam = function () {
    if (activeCam == camFPS) {
        activeCam = camTPS;
        controlTPS.enable = true;
    } else {
        activeCam = camFPS;
        controlTPS.enable = false;
    }
}

var changeChar = function () {
    var next;
    if (char) {
        if (currentChar < char.length-1) {
            next = currentChar + 1;
        } else {
            next = 0;
        }
        for (let i in char) {
            if (i != next) {
                scene.remove(char[i].mesh);
            }
        }
    }
    if (soundBack[currentChar]) {
        soundBack[currentChar].pause();
    }
    if (soundBack[next]) {
        soundBack[next].play();
    }
    
    scene.add(char[next].mesh);
    currentChar = next;
    charBox = new THREE.Box3().setFromObject(char[currentChar].mesh);
}

var camAnimation = function () {
    let vetor1 = new THREE.Vector3();
    let vetor2 = new THREE.Vector3();
    camFPS.getWorldDirection(vetor1);
    char[currentChar].mesh.getWorldDirection(vetor2);
    vetor1.add(char[currentChar].mesh.position);
    vetor2.add(char[currentChar].mesh.position);
    char[currentChar].mesh.lookAt(new THREE.Vector3(vetor1.x, vetor2.y, vetor1.z));

    char[currentChar].mesh.position.set(camFPS.position.x, char[currentChar].mesh.position.y, camFPS.position.z);
    camFPS.position.y = char[currentChar].height;
}

var charAnimation = function () {
    let direction = new THREE.Vector3();
    char[currentChar].mesh.getWorldDirection(direction);
    if (keyPressed['w']) {
        if (activeCam == camTPS) {
            camTPS.getWorldDirection(direction);
            let lookAt = direction.clone();
            lookAt.add(camFPS.position);
            camFPS.lookAt(lookAt);
        }
        camFPS.position.z += char[currentChar].velocity * direction.z;
        camFPS.position.x+=char[currentChar].velocity*direction.x;
        camTPS.position.z+=char[currentChar].velocity*direction.z;
        camTPS.position.x+=char[currentChar].velocity*direction.x;
    }
    else if (keyPressed['s']) {
        if (activeCam == camTPS) {
            camTPS.getWorldDirection(direction);
            direction.applyAxisAngle(new THREE.Vector3(0, 1, 0), Math.PI);
            let lookAt = direction.clone();
            lookAt.add(camFPS.position);
            camFPS.lookAt(lookAt);
            if (char[currentChar].Animation.animationArray[1].timeScale == -1) {
                char[currentChar].Animation.animationArray[1].timeScale = 1;
            }
            camFPS.position.z+=char[currentChar].velocity*direction.z;
            camFPS.position.x+=char[currentChar].velocity*direction.x;
            camTPS.position.z+=char[currentChar].velocity*direction.z;
            camTPS.position.x+=char[currentChar].velocity*direction.x;
        } else {
            camFPS.position.z-=char[currentChar].velocity*direction.z;
            camFPS.position.x-=char[currentChar].velocity*direction.x;
            camTPS.position.z-=char[currentChar].velocity*direction.z;
            camTPS.position.x-=char[currentChar].velocity*direction.x;
        }
    }
    else if (keyPressed['a']) {
        if (activeCam == camTPS) {
            camTPS.getWorldDirection(direction);
            direction.applyAxisAngle(new THREE.Vector3(0, 1, 0), Math.PI/2);            
            let lookAt = direction.clone();
            lookAt.add(camFPS.position);
            camFPS.lookAt(lookAt);
        } else {
            direction.applyAxisAngle(new THREE.Vector3(0, 1, 0), Math.PI/2);            
        }
        camFPS.position.z+=char[currentChar].velocity*direction.z;
        camFPS.position.x+=char[currentChar].velocity*direction.x;
        camTPS.position.z+=char[currentChar].velocity*direction.z;
        camTPS.position.x+=char[currentChar].velocity*direction.x;
    }
    else if (keyPressed['d']) {
        if (activeCam == camTPS) {
            camTPS.getWorldDirection(direction);
            direction.applyAxisAngle(new THREE.Vector3(0, 1, 0), -Math.PI/2);            
            let lookAt = direction.clone();
            lookAt.add(camFPS.position);
            camFPS.lookAt(lookAt);
        } else {
            direction.applyAxisAngle(new THREE.Vector3(0, 1, 0), -Math.PI/2);            
        }
        camFPS.position.z+=char[currentChar].velocity*direction.z;
        camFPS.position.x+=char[currentChar].velocity*direction.x;
        camTPS.position.z+=char[currentChar].velocity*direction.z;
        camTPS.position.x+=char[currentChar].velocity*direction.x;
    }

    charBox.setFromObject(char[currentChar].mesh.children[0]);
}

var animation = function (){
    requestAnimationFrame(animation);

    sunAnimation();

    let timer = clock.getDelta();

    camAnimation();

    if(Object.keys(elements).length > 0){
        Object.keys(elements).forEach(element =>{
            if(elements[element].loaded && elements[element].animated){
                elements[element].Animation.mixer.update(timer);
            }
        })
    }

    charAnimation();

    collisions();

    renderer.render(scene, activeCam);
}

var collisions = function(){
    for (let element of Object.keys(elements)) {
        var direction = new THREE.Vector3();
        camFPS.getWorldDirection(direction);        

        var copy = char[currentChar].mesh.clone();
        // console.log(copy.position);
        copy.position.z+=char[currentChar].velocity*2*direction.z;
        copy.position.x+=char[currentChar].velocity*2*direction.x;

        var nextBox = new THREE.Box3().setFromObject(copy); 
        
        if ((elements[element].box.intersectsBox(nextBox) && elements[element].constructor.name != "Character") || char[currentChar].mesh.position.x >= 1000 || char[currentChar].mesh.position.x <= -1000 || char[currentChar].mesh.position.z >= 1000 || char[currentChar].mesh.position.z <= -1000) {
            var direction = new THREE.Vector3();
            camFPS.getWorldDirection(direction);
            direction.applyAxisAngle(new THREE.Vector3(0, 1, 0), Math.PI); 
            
            camFPS.position.z+=char[currentChar].velocity*direction.z;
            camFPS.position.x+=char[currentChar].velocity*direction.x;
            camTPS.position.z+=char[currentChar].velocity*direction.z;
            camTPS.position.x+=char[currentChar].velocity*direction.x;
        }
    }
}

var loadSongs = function () {
    const audioLoader = new THREE.AudioLoader();
	audioLoader.load( 'assets/sound/samurai_song.mp3', 
	function( buffer ) {
		soundBack[0].setBuffer( buffer );
		soundBack[0].setLoop( true );
		soundBack[0].setVolume( 0.08 );
	});

    audioLoader.load( 'assets/sound/demon_song.mp3', 
	function( buffer ) {
		soundBack[1].setBuffer( buffer );
		soundBack[1].setLoop( true );
		soundBack[1].setVolume( 0.08 );
    });
    
    audioLoader.load( 'assets/sound/zombie_song.mp3', 
	function( buffer ) {
		soundBack[2].setBuffer( buffer );
		soundBack[2].setLoop( true );
		soundBack[2].setVolume( 0.08 );
	});

    audioLoader.load( 'assets/sound/troll_song.mp3', 
	function( buffer ) {
		soundBack[3].setBuffer( buffer );
		soundBack[3].setLoop( true );
		soundBack[3].setVolume( 0.08 );
	});
}

var main = async function(){
    scene = new THREE.Scene();

	scene.background = new THREE.Color(0x00bfff);

    camFPS = new THREE.PerspectiveCamera(40, window.innerWidth / window.innerHeight, 5, 10000);

    camTPS = new THREE.PerspectiveCamera(40, window.innerWidth/window.innerHeight, 5, 10000);

    listener = new THREE.AudioListener();
	camFPS.add( listener );
    soundBack[0] = new THREE.Audio( listener );
    soundBack[1] = new THREE.Audio( listener );
    soundBack[2] = new THREE.Audio( listener );
    soundBack[3] = new THREE.Audio( listener );
    loadSongs();

    activeCam = camTPS

    renderer = await Util.redererInit();

    controlFPS = new PointerLockControls(camFPS, document.body);
    controlTPS = new OrbitControls(camTPS, renderer.domElement);

    ground = Util.groundInit(scene);
    
    initSky();

    document.addEventListener( 'keydown', function () {
        if (activeCam == camFPS) {
            controlFPS.lock();
        } else {
            controlFPS.unlock();
        }
    } );

    lights['directional'] = new Light({
        "position" : {
            "x" : 0,
            "y" : 1000,
            "z" : 20
        },
        "color" : 0xf1f1f1,
        "intesity" : 1,
        "type" : "DirectionalLight"
    });
    sunAnchor.position.set(0,0,0);
    await lights.directional.load(sunAnchor);
    scene.add(sunAnchor);

    lights.directional.mesh.shadow.mapSize.width = 4096;
    lights.directional.mesh.shadow.mapSize.height = 4096;
    lights.directional.mesh.shadow.camera.left = 1000;
    lights.directional.mesh.shadow.camera.bottom = 1000;
    lights.directional.mesh.shadow.camera.right = -1000;
    lights.directional.mesh.shadow.camera.top = -1000;
    lights.directional.mesh.shadow.camera.far = 100000;
    lights.directional.mesh.target = ground;

    Util.initElements(elements);
    Util.initVegetation(scene);

    lights['ambient'] = new Light({
        "color" : 0xffffff,
        "intesity" : 0.2,
        "type" : "ambientlight"
    });

    lights['ambient'].load(scene);

    await loadElements(scene);
    changeChar();

    lights['pointLight1'] = new Light({
        "color" : 0xffffff,
        "intesity" : 0.8,
        "type": "POINTLIGHT",
        "distance": 100,
        "decay": 1,
        "position": {
            "x": elements['gazebo'].mesh.position.x-6,
            "y": 5,
            "z": elements['gazebo'].mesh.position.z+2.4,
        }
    });

    lights['pointLight1'].load(scene);

    lights['pointLight2'] = new Light({
        "color" : 0xffffff,
        "intesity" : 0.8,
        "type": "POINTLIGHT",
        "distance": 100,
        "decay": 1,
        "position": {
            "x": elements['gazebo'].mesh.position.x+6,
            "y": 5,
            "z": elements['gazebo'].mesh.position.z-2.4,
        }
    });

    lights['pointLight2'].load(scene);

    controlTPS.target = camFPS.position;

    camTPS.position.set(0, 0, 30);
    camTPS.lookAt(camFPS.position)

    animation();

    renderer.render(scene, camFPS);

    window.addEventListener( 'resize', onWindowResize );
}

function onWindowResize() {

    camFPS.aspect = window.innerWidth / window.innerHeight;
    camFPS.updateProjectionMatrix();

    camTPS.aspect = window.innerWidth / window.innerHeight;
    camTPS.updateProjectionMatrix();

    renderer.setSize( window.innerWidth, window.innerHeight );

}

document.addEventListener('keydown', onKeyDown);
document.addEventListener('keyup', onKeyUp);

window.onload = main();
