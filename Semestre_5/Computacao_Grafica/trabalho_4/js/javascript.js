var scene, camera, render, light, control, elements = new Array(), anchors = new Array();

var objLoader = new THREE.OBJLoader();
var fbxLoader = new THREE.FBXLoader();
var textLoader = new THREE.TextureLoader();

var createGUI = function () {
    const gui = new dat.GUI();

    paramGUI = {
        vision: "none"
    }

    //vision
    let options = ["alligator", "black-panther", "camel", "phoenix", "pig", "ragdoll-cat", "scorpion", "siberian-husky", "toucan", "triceratops"];
    let vision = gui.addFolder("Vision");
    let select = vision.add(paramGUI, 'vision').options(options).name("Select");
    select.onChange(function (param) {
        if (param == "none") { }
        else{
            camera.position.x = elements[param].position.x - 30;
            camera.position.y = elements[param].position.y + 40;
            camera.position.z = elements[param].position.z;
            camera.lookAt(elements[param].position);

            control.target.x = elements[param].position.x;
            control.target.y = elements[param].position.y;
            control.target.z = elements[param].position.z;
        }
	});

    gui.open();
}

var loadObject = function(link, texture_link, initial_position, initial_scale, initial_rotation,  name, normalMap_link = null, displacementMap_link = null, metalnessMap_link = null, roughnessMap_link = null){
    fbxLoader.load(
        link,
        function (obj) {
            let material = new THREE.MeshStandardMaterial();

            obj.traverse(
                function(child){
                    if (child instanceof THREE.Mesh){
                        child.material = material;
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

var ilumination = function(){
    let spot = new THREE.SpotLight(0xffffff);
	spot.position.set(0,1000,0);
    scene.add(spot);
    
	let light = new THREE.HemisphereLight( scene.background.getHex() , 0x285603, 0.2 );
    scene.add( light );
}

var animation = function (){
    requestAnimationFrame(animation);

    render.render(scene, camera);
}

var ground = function () {
    let textureGround = textLoader.load('assets/grass/texture.jpg');
    textureGround.wrapS = textureGround.wrapT = THREE.RepeatWrapping;
    textureGround.repeat.set(30, 30);
    textureGround.anisotropy = 5;
    textureGround.encoding = THREE.sRGBEncoding;

    let materialGround = new THREE.MeshStandardMaterial({ map: textureGround });
    materialGround.normalMap = textLoader.load('assets/grass/normal.jpg');
    materialGround.normalMap.wrapS = materialGround.normalMap.wrapT = THREE.RepeatWrapping;
    materialGround.normalMap.repeat.set(30, 30);

    let ground = new THREE.Mesh(new THREE.PlaneBufferGeometry(1000,1000), materialGround);

	ground.rotation.x = -Math.PI/2;
	ground.position.y-=10;
    scene.add(ground);
}

var init = function (){
    scene = new THREE.Scene();

	scene.background = new THREE.Color(0x00bfff);
    ground();

	scene.fog = new THREE.Fog(scene.background.getHex() , 50, 180);

    camera = new THREE.PerspectiveCamera(40, window.innerWidth/window.innerHeight, 1, 180);

    render = new THREE.WebGLRenderer();
    render.setSize(window.innerWidth, window.innerHeight);
    document.body.appendChild(render.domElement);

    camera.position.x = 0;
    camera.position.y = 0;
    camera.position.z = -10;

    createGUI();

    ilumination();
    control = new THREE.OrbitControls(camera, render.domElement);

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
    
    for (let i = 0; i < 10; i++){
        rotations[i].y = Math.random() * (2 * Math.PI);
    }
    
    loadObject("assets/scorpion/Scorpion.fbx", "assets/scorpion/texture.png", positions[0], scales[0], rotations[0],  "scorpion"); 

    loadObject("assets/camel/Camel_low.FBX","assets/camel/Texture/texture.png", positions[1], scales[1], rotations[1], "camel", "assets/camel/Texture/normal.png", null, "assets/camel/Texture/metalness.png",  "assets/camel/Texture/roughness.jpg");

    loadObject("assets/phoenix/Phoenix.fbx","assets/phoenix/texture.png", positions[2], scales[2], rotations[2], "phoenix");

    loadObject("assets/pig/Pig_low.FBX","assets/pig/Texture/texture.png", positions[3], scales[3], rotations[3], "pig", "assets/pig/Texture/normal.png", null, "assets/pig/Texture/metalness.png",  "assets/pig/Texture/roughness.jpg");

    loadObject("assets/ragdoll-cat/Ragdoll.fbx","assets/ragdoll-cat/texture.png", positions[4], scales[4], rotations[4], "ragdoll-cat");

    loadObject("assets/toucan/Toucan.fbx","assets/toucan/texture.png", positions[5], scales[5], rotations[5], "toucan");

    loadObject("assets/siberian-husky/Siberian Husky.fbx", "assets/siberian-husky/texture.png", positions[6], scales[6], rotations[6], "siberian-husky");
    
    loadObject("assets/black-panther/Black Panther.fbx", "assets/black-panther/texture.png", positions[7], scales[7], rotations[7], "black-panther");
    
    loadObject("assets/triceratops/triceratops.fbx","assets/triceratops/texture.png", positions[8], scales[8], rotations[8], "triceratops");

    loadObject("assets/alligator/Alligator.fbx","assets/alligator/texture.png", positions[9], scales[9], rotations[9], "alligator");

    animation();

    render.render(scene, camera);
}

window.onload = this.init();