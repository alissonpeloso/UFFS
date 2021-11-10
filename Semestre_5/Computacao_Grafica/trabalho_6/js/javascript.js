//Aluno: Alisson Luan de Lima Peloso

//Teclas W,A,S,D controlam o samurai
//Clique e arraste para mudar a visão/direção

var scene, camera, renderer, light, control, elements = new Array(), anchors = new Array(), lights = new Array(), animationArray = new Object(), charGroup = new THREE.Group();

var objLoader = new THREE.OBJLoader();
var fbxLoader = new THREE.FBXLoader();
var textLoader = new THREE.TextureLoader();
var controls;
var clock = new THREE.Clock();
var keyPressed = []; 
keyPressed['shift'] = false;
var velociadadeChar = 1;

var onKeyUp = function (e){
    if(e.keyCode == 16){
        keyPressed['shift'] = false;
    }

    if(e.keyCode == 87){
        keyPressed['w'] = false;
        changeAnimation(0,'samurai');
    }

    if(e.keyCode == 83){
        keyPressed['s'] = false;
        animationArray['samurai'].animation_list[1].timeScale = 1;
        changeAnimation(0,'samurai');
    }

    if(e.keyCode == 32){
        keyPressed['space'] = false;
    }
}

var onKeyDown = function (e){
    console.log(e.keyCode);
    if(e.keyCode == 84){
        controls.enabled = !controls.enabled;
    }

    if(e.keyCode == 87){
        keyPressed['w'] = true;
        changeAnimation(1,'samurai');
    }

    if(e.keyCode == 83){
        keyPressed['s'] = true;
        changeAnimation(1,'samurai');
        animationArray['samurai'].animation_list[1].timeScale = -1;
    }

    if(e.keyCode == 16){
        keyPressed['shift'] = true;
    }

    if(e.keyCode == 32){
        keyPressed['space'] = true;
        changeAnimation(2,'samurai');
    }
}

function initSky() {
    sky = new THREE.Sky();
    sky.scale.setScalar( 450000 );
    scene.add( sky );

    sun = new THREE.Vector3();

    const uniforms = sky.material.uniforms;
    uniforms[ 'turbidity' ].value = 10;
    uniforms[ 'rayleigh' ].value = 3;
    uniforms[ 'mieCoefficient' ].value = 0.05;
    uniforms[ 'mieDirectionalG' ].value = 0.7;

    sun.setFromSphericalCoords( 1000, 0, 0 );

    uniforms[ 'sunPosition' ].value.copy( sun );

    elements['sun'] = sun;
    elements['sun_position'] = uniforms['sunPosition'];

    renderer.toneMappingExposure = renderer.toneMappingExposure;
    renderer.render( scene, camera );
}

var sunAnimation = function (){
    elements.diretional_anchor.rotation.x+= 0.0003;
    if(elements.diretional_anchor.rotation.x >= Math.PI*2){
        elements.diretional_anchor.rotation.x = 0;
    }

    elements.sun.setFromSphericalCoords( 1000, elements.diretional_anchor.rotation.x , 0 );

    elements['sun_position'].value.copy(elements['sun'])
}

var loadObject = function(typeLoader, link, texture_link, initial_position, initial_scale, initial_rotation,  name, normalMap_link = null, displacementMap_link = null, metalnessMap_link = null, roughnessMap_link = null, emissiveMap_link = null, animation = false, animation_links=null, firstPerson = false){
    let loader = typeLoader == "obj"? objLoader : fbxLoader;

    loader.load(
        link,
        function (obj) {
            let material = new THREE.MeshStandardMaterial();

            obj.traverse(
                function(child){
                    if (child instanceof THREE.Mesh){
                        child.material = material;
                        child.castShadow = true;
						child.receiveShadow = true;
                    }
                }
            );

            material.map = textLoader.load(texture_link);
            if (normalMap_link) {
                material.normalMap = textLoader.load(normalMap_link);
            }
            if (displacementMap_link) {
                material.displacementMap = textLoader.load(displacementMap_link);
            }
            if (metalnessMap_link) {
                material.metalnessMap = textLoader.load(metalnessMap_link);
            }
            if (roughnessMap_link) {
                material.roughnessMap = textLoader.load(roughnessMap_link);
            }
            if (emissiveMap_link) {
                material.emissiveMap = textLoader.load(emissiveMap_link);
            }

            //set scale
            obj.scale.x = initial_scale.x;
            obj.scale.y = initial_scale.y;
            obj.scale.z = initial_scale.z;

            //set position
            obj.position.x = initial_position.x;
            obj.position.y = initial_position.y;
            obj.position.z = initial_position.z;

            //set rotation
            obj.rotation.x = initial_rotation.x;
            obj.rotation.y = initial_rotation.y;
            obj.rotation.z = initial_rotation.z;

            elements[name] = obj;

            scene.add(elements[name]);

            if (animation){
                let mixer = new THREE.AnimationMixer(obj);
                animationArray[name] = new Object();
                animationArray[name].animation_list = new Array();
                animationArray[name].mixer = mixer;

                animationArray[name].animation_list.push(mixer.clipAction(obj.animations[0]));
                animationArray[name].current_animation = null;

                if(animation_links){
                    animation_links.forEach(animation_link => {
                        fbxLoader.load(
                            animation_link,
                            function (obj){
                                animationArray[name].animation_list.push(mixer.clipAction(obj.animations[0]));
                            },
                            function(loading){
                                console.log(loading.loaded/loading.total*100 + "%");
                            },
                            function (error) {  
                                console.log("Erro ao carregar "+name+":"+animation_link+": "+error);
                            }
                        )
                    });
                } else{
                    if(obj.animations.length > 1){
                        for (let index = 1; index < obj.animations.length; index++) {
                            animationArray[name].animation_list.push(mixer.clipAction(obj.animations[index]));
                        }
                    }
                }
                changeAnimation(0,name)
            }

            if (firstPerson){
                charGroup.add(obj);
                charGroup.add(camera);
                obj.position.z = camera.position.z-35;
                obj.rotation.y+=Math.PI;

                scene.add(charGroup);
            }

            console.log(name+" carregado com sucesso!");
        },
        function(loading){
            console.log(loading.loaded/loading.total*100 + "%");
        },
        function (error) {  
            console.log("Erro ao carregar "+name+": "+error);
        }
    );
}

var changeAnimation = function (new_animation, name) {
	if (new_animation != animationArray[name].current_animation && animationArray[name].animation_list[new_animation]){
		prevAnimation = animationArray[name].current_animation;
		animationArray[name].current_animation = new_animation;
		animationArray[name].animation_list[new_animation].reset();
        if(prevAnimation != null){
            animationArray[name].animation_list[prevAnimation].stop();
        }
        animationArray[name].animation_list[new_animation].play();
	}
}

var directionalLight = function(){
    let light = new THREE.DirectionalLight(0xf1f1f1, 1, 1000);
    light.castShadow = true;

    light.shadow.mapSize.width = 4096;
    light.shadow.mapSize.height = 4096;
    light.shadow.camera.left = 1000;
    light.shadow.camera.bottom = 1000;
    light.shadow.camera.right = -1000;
    light.shadow.camera.top = -1000;
    light.shadow.camera.far = 100000;

    scene.add(new THREE.DirectionalLightHelper(light));

    light.position.y = 10000;
    light.target = elements['ground'];

    let anchor = new THREE.Group();
    anchor.position.set(0,0,0);
    anchor.add(light);

    scene.add(anchor);

    elements['diretional_anchor'] = anchor;
    elements['diretional_light'] = light;

}

var pointLight = function(position, color, intesity, distance){
    let light = new THREE.PointLight(color, intesity, distance);
    light.castShadow = true; //Não consegui resolver o problema aqui

    light.position.set(position.x, position.y, position.z)
    scene.add(light)

    lights.push(light);
}

var ambientLight = function () {
    let light = new THREE.AmbientLight(0x666666, 0.1);
    scene.add(light);
}

var hemisphereLight = function () {
    let light = new THREE.HemisphereLight( 0xe7edf0 , 0x144f01, 0.1 );
    scene.add( light );
}

var ilumination = function(){
    directionalLight();
    ambientLight();
    hemisphereLight();
}

var animation = function (){
    requestAnimationFrame(animation);

    sunAnimation();

	locomotion();

    let timer = clock.getDelta()

    if (controls){
		controls.update(timer);
        if(!keyPressed['shift']){
            controls.movementSpeed = 20;
        } else{
            controls.movementSpeed = 40;
        }
    }
    camera.position.y = 2;

    if(elements.diretional_anchor.rotation.x >= Math.PI/2 && elements.diretional_anchor.rotation.x <= Math.PI*1.5){
        for (const key in lights) {
            if (!lights[key].visible) {
                turnTheLightOn(lights[key]);
            }
        }
    }
    else{
        for (const key in lights) {
            if (lights[key].visible) {
                turnTheLightOff(lights[key]);
            }
        }
    }


    if(animationArray != undefined){
        if(Object.keys(animationArray).length > 0){
            Object.keys(animationArray).forEach(element =>{
                animationArray[element].mixer.update(timer);
            })
        }
    }

    renderer.render(scene, camera);
}

var firstPersonControls = function () {
    controls = new THREE.FirstPersonControls(camera, renderer.domElement);
    controls.movementSpeed = 20;
	controls.lookSpeed = 0.1;
	controls.constrainVertical = true;
	controls.verticalMin = 0;
	controls.verticalMax = Math.PI;
    if(keyPressed["T"]){
        controls.enabled = false;
    }
}

var locomotion = function(){
	if (camera){
		direction = camera.getWorldDirection(new THREE.Vector3(0,0,0));
	
		if (keyPressed['w']){
			charGroup.position.z+=velociadadeChar*direction.z;
			charGroup.position.x+=velociadadeChar*direction.x;
		}
        else if (keyPressed['s']){
			charGroup.position.z-=velociadadeChar*direction.z;
			charGroup.position.x-=velociadadeChar*direction.x;
		}
	}
}

var toRadians = function (value){
	return value *(Math.PI/180);
}

var isClicking = false;

var click = function(){
    isClicking = true;
}
 
var clickUp = function(){
    isClicking = false;
}

var prevMouse = {
	x:0,
	y:0
};

var movimentaMouser = function(e){
	let diffMouse = {
		x: e.offsetX - prevMouse.x,
		y: e.offsetY - prevMouse.y
	}

	if (isClicking){
		let rotacaoElemento = new THREE.Quaternion().setFromEuler( new THREE.Euler(0, toRadians(-diffMouse.x)*0.1, 0, 'XYZ'));

		charGroup.quaternion.multiplyQuaternions(rotacaoElemento, charGroup.quaternion);
	}

	prevMouse = {
		x:e.offsetX,
		y:e.offsetY
	};
}

var ground = function () {
    let textureGround = textLoader.load('assets/grass/texture.jpg');
    console.log("AQUI PORA");
    console.log(textureGround);
    textureGround.wrapS = textureGround.wrapT = THREE.RepeatWrapping;
    textureGround.repeat.set(30, 30);
    textureGround.anisotropy = 16;
    textureGround.encoding = THREE.sRGBEncoding;

    let materialGround = new THREE.MeshStandardMaterial({ map: textureGround });
    materialGround.normalMap = textLoader.load('assets/grass/normal.jpg');
    materialGround.normalMap.wrapS = materialGround.normalMap.wrapT = THREE.RepeatWrapping;
    materialGround.normalMap.repeat.set(30, 30);

    let ground = new THREE.Mesh(new THREE.PlaneBufferGeometry(2000,2000), materialGround);
    elements['ground'] = ground;
    
	ground.rotation.x = -Math.PI/2;
    ground.position.y -= 10;
    ground.receiveShadow = true;
    ground.castShadow = true;
    
    let underGround = new THREE.Mesh(new THREE.PlaneBufferGeometry(1000,1000));

    underGround.position.y = -12
	underGround.rotation.x = -Math.PI/2;
    underGround.receiveShadow = true;
    underGround.castShadow = true;

    scene.add(underGround)
    scene.add(ground);
}

var turnTheLightOn = function(light){
    light.visible = true;
}

var turnTheLightOff = function(light){
    light.visible = false;
}

var init = async function (){
    scene = new THREE.Scene();

	scene.background = new THREE.Color(0x00bfff);

    camera = new THREE.PerspectiveCamera(40, window.innerWidth/window.innerHeight, 1, 10000);

    renderer = new THREE.WebGLRenderer({antialias: true});
    renderer.shadowMap.enabled = true;
    renderer.shadowMap.type = THREE.PCFSoftShadowMap;
    renderer.setSize(window.innerWidth, window.innerHeight);
    renderer.setPixelRatio( window.devicePixelRatio );
    renderer.outputEncoding = THREE.sRGBEncoding;
    renderer.toneMapping = THREE.ACESFilmicToneMapping;
    renderer.toneMappingExposure = 0.5;
    document.body.appendChild(renderer.domElement);

    ground();
    initSky();

    camera.position.set( 0, 0, 30 );
    
    var positions = Array(), scales = Array(), rotations = Array();

    scales[0] = { x: 0.007, y: 0.007, z: 0.007 };
    rotations[0] = {x : 0, y : 0, z : 0};
    positions[0] = { x: 173, y: -10.6, z: -250};

    scales[1] = { x: 4, y: 4, z: 4 };
    rotations[1] = { x: 0, y: Math.PI, z: 0 };
    positions[1] = {x : -55, y : -10, z : -120};

    scales[2] = {x : 0.05, y : 0.05, z : 0.05}
    rotations[2] = { x: 0, y: 0, z: 0 };
    positions[2] = { x: -196, y: 0, z: 75};

    scales[3] = { x: 4, y: 4, z: 4 };
    rotations[3] = {x : 0, y : 0, z : 0};
    positions[3] = {x : -111, y : -10, z : -72};

    scales[4] = { x: 0.01, y: 0.01, z: 0.01 };
    rotations[4] = {x : 0, y : 0, z : 0};
    positions[4] = {x : -142, y : -10, z : -28};

    scales[5] = { x: 0.008, y: 0.008, z: 0.008 };
    rotations[5] = {x : 0, y : 0, z : 0};
    positions[5] = { x: -157, y: -10.3, z: 46};

    scales[6] = { x: 0.017, y: 0.017, z: 0.017 };
    rotations[6] = {x : 0, y : 0, z : 0};
    positions[6] = {x : 16, y : -10, z : 89};

    scales[7] = { x: 0.1, y: 0.1, z: 0.1 };
    rotations[7] = {x : 0, y : 0, z : 0};
    positions[7] = {x : -239, y : -10, z : -167};

    scales[8] = { x: 0.04, y: 0.04, z: 0.04 };
    rotations[8] = {x : 0, y : 0, z : 0};
    positions[8] = { x: 202, y: -10.5, z: 64};

    scales[9] = { x: 0.014, y: 0.014, z: 0.014 };
    rotations[9] = { x: 0, y: Math.PI / 2, z: 0 };
    positions[9] = { x: 247, y: -10, z: 250 };

    scales[10] = { x: 1, y: 1, z: 1 };
    rotations[10] = { x: 0, y: 0, z: 0};
    positions[10] = { x: 0, y: -10, z: -50};

    scales[11] = { x: 0.02, y: 0.02, z: 0.02 };
    rotations[11] = { x: 0, y: 0, z: 0};
    positions[11] = { x: -60, y: -10, z: 0};

    scales[12] = { x: 0.5, y: 0.5, z: 0.5 };
    rotations[12] = { x: 0, y: 0, z: 0};
    positions[12] = { x: -119, y: -10, z: 87};

    scales[13] = { x: 3, y: 3, z: 3 };
    rotations[13] = { x: 0, y: 0, z: 0};
    positions[13] = { x: 30, y: 26, z: 200};
    
    for (let i = 0; i < 10; i++){
        rotations[i].y = Math.random() * (2 * Math.PI);
    }
    
	document.addEventListener('mousemove', movimentaMouser); //pegar um evento do teclado. Aperta tecla.

    loadObject("fbx","assets/scorpion/Scorpion.fbx", "assets/scorpion/Scorpion_texture.png", positions[0], scales[0], rotations[0], "scorpion"); 

    loadObject("fbx","assets/camel/Camel_low.FBX","assets/camel/Texture/texture.png", positions[1], scales[1], rotations[1], "camel", "assets/camel/Texture/normal.png", null, "assets/camel/Texture/metalness.png",  "assets/camel/Texture/roughness.jpg");

    loadObject("fbx","assets/phoenix/Phoenix.fbx","assets/phoenix/Phoenix_texture.png", positions[2], scales[2], rotations[2], "phoenix");

    loadObject("fbx","assets/pig/Pig_low.FBX","assets/pig/Texture/texture.png", positions[3], scales[3], rotations[3], "pig", "assets/pig/Texture/normal.png", null, "assets/pig/Texture/metalness.png",  "assets/pig/Texture/roughness.jpg");

    loadObject("fbx","assets/ragdoll-cat/Ragdoll.fbx","assets/ragdoll-cat/Ragdoll_texture.png", positions[4], scales[4], rotations[4], "ragdoll-cat");

    loadObject("fbx","assets/toucan/Toucan.fbx","assets/toucan/Toucan_texture.png", positions[5], scales[5], rotations[5], "toucan");

    loadObject("fbx","assets/siberian-husky/Siberian Husky.fbx", "assets/siberian-husky/texture.png", positions[6], scales[6], rotations[6], "siberian-husky");
    
    loadObject("fbx","assets/black-panther/Black Panther.fbx", "assets/black-panther/texture.png", positions[7], scales[7], rotations[7], "black-panther");
    
    loadObject("fbx","assets/triceratops/triceratops.fbx","assets/triceratops/texture.png", positions[8], scales[8], rotations[8], "triceratops");

    loadObject("fbx","assets/statue of liberty/Statue of Liberty.fbx","assets/statue of liberty/UV Statue Of Liberty.png", positions[10], scales[10], rotations[10], "statue");

    loadObject("obj","assets/barrel/Barrel.obj","assets/barrel/Barrel_mat_color.png", positions[12], scales[12], rotations[12], "barrel", "assets/barrel/Barrel_mat_nmap.png");

    loadObject("obj","assets/billboard/billboard.obj","assets/billboard/billboard_normal.png", positions[13], scales[13], rotations[13], "billboard", "assets/billboard/billboard_normal.png");

    loadObject("obj","assets/chinese-lamp/lamp.obj","assets/chinese-lamp/lamp_albedo.jpeg", { x: 15, y: -10, z: 0}, { x: 1.3, y: 1.3, z: 1.3 }, { x: 0, y: 0, z: 0}, "lightpost", null, null, "assets/chinese-lamp/lamp_metallic.jpeg", "assets/chinese-lamp/lamp_roughness.jpeg");
    pointLight({ x: 15, y: -4.5, z: 0}, 0xe6e6b1, 0.3, 0)

    loadObject("obj","assets/chinese-lamp/lamp.obj","assets/chinese-lamp/lamp_albedo.jpeg", { x: -25, y: -10, z: 0}, { x: 1.3, y: 1.3, z: 1.3 }, { x: 0, y: 0, z: 0}, "lightpost2", null, null, "assets/chinese-lamp/lamp_metallic.jpeg", "assets/chinese-lamp/lamp_roughness.jpeg");
    pointLight({ x: -25, y: -4.5, z: 0}, 0xFFFFFF, 0.3, 0);

    loadObject("fbx", "assets/samurai/Samurai_Idle.fbx", "assets/samurai/UV Samurai.png", {x:0, y:-10, z:0}, {x:0.015, y:0.015, z:0.015},{x:0, y:0, z:0},"samurai", null, null, null, null, null, true, ["assets/samurai/Samurai_Run.fbx", "assets/samurai/Samurai_Jump.fbx", "assets/samurai/Samurai_Attack.fbx", "assets/samurai/Samurai_Damage.fbx", "assets/samurai/Samurai_Dead.fbx"], true);

    loadObject("fbx","assets/basketball-player/Animations/Dribble.fbx","assets/basketball-player/Basketball_player_texture.png", positions[11], scales[11], rotations[11], "basketball_player", null, null, null, null, null, true, ["assets/basketball-player/Animations/Dribble.fbx"]);

    loadObject("fbx","assets/alligator/Alligator.fbx","assets/alligator/texture.png", positions[9], scales[9], rotations[9], "alligator", null, null, null, null, null, true);

    //Outdoor Lights
    pointLight({x: 29.3, y: 46.1, z: 190.8}, 0xFFFFFF, 0.2, 0);
    pointLight({x: 43.1, y: 46.1, z: 190.8}, 0xFFFFFF, 0.2, 0);
    pointLight({x: 15.5, y: 46.1, z: 190.8}, 0xFFFFFF, 0.2, 0);

    pointLight({x: 29.3, y: 46.1, z: 209}, 0xFFFFFF, 0.2, 0);
    pointLight({x: 43.1, y: 46.1, z: 209}, 0xFFFFFF, 0.2, 0);
    pointLight({x: 15.5, y: 46.1, z: 209}, 0xFFFFFF, 0.2, 0);

    ilumination();
    // firstPersonControls();

    document.addEventListener('keydown', onKeyDown);
	document.addEventListener('keyup', onKeyUp);
    document.addEventListener('mouseup', clickUp);
    document.addEventListener('mousedown', click);

    animation();

    renderer.render(scene, camera);
}

window.onload = this.init();