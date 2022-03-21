import * as THREE from '../threejs/three.module.js';
import { Element } from "../class/element.js";
import { Character } from '../class/character.js';

var redererInit = async function () {
    var renderer = new THREE.WebGLRenderer({antialias: true});
    renderer.shadowMap.enabled = true;
    renderer.shadowMap.type = THREE.PCFSoftShadowMap;
    renderer.setSize(window.innerWidth, window.innerHeight);
    renderer.setPixelRatio( window.devicePixelRatio );
    renderer.outputEncoding = THREE.sRGBEncoding;
    renderer.toneMapping = THREE.ACESFilmicToneMapping;
    renderer.toneMappingExposure = 0.5;
    document.body.appendChild(renderer.domElement);
    return renderer;
}

var groundInit = function (scene) {
    var textureLoader = new THREE.TextureLoader();

    let textureGround = textureLoader.load('assets/ground/Ground027_1K-JPG/Color.jpg');

    textureGround.wrapS = textureGround.wrapT = THREE.RepeatWrapping;
    textureGround.repeat.set(30, 30);
    textureGround.anisotropy = 16;
    textureGround.encoding = THREE.sRGBEncoding;

    let materialGround = new THREE.MeshStandardMaterial({ map: textureGround });
    materialGround.normalMap = textureLoader.load('assets/grass/normal.jpg');
    materialGround.normalMap.wrapS = materialGround.normalMap.wrapT = THREE.RepeatWrapping;
    materialGround.normalMap.repeat.set(30, 30);

    materialGround.displacementMap = textureLoader.load('assets/ground/Ground027_1K-JPG/Displacement.jpg');

    materialGround.normalMap = textureLoader.load('assets/ground/Ground027_1K-JPG/NormalGL.jpg');

    materialGround.roughnessMap = textureLoader.load('assets/ground/Ground027_1K-JPG/Roughness.jpg');

    let ground = new THREE.Mesh(new THREE.PlaneBufferGeometry(5000,5000), materialGround);
    
	ground.rotation.x = -Math.PI/2;
    ground.position.y -= 10;
    ground.receiveShadow = true;
    ground.castShadow = true;
    
    let underGround = new THREE.Mesh(new THREE.PlaneBufferGeometry(5000,5000));

    underGround.position.y = -12
	underGround.rotation.x = -Math.PI/2;
    underGround.receiveShadow = true;
    underGround.castShadow = true;

    scene.add(underGround)
    scene.add(ground);

    return ground;
}

var initElements = function (elements) {
    elements['samurai'] = new Character({
        "name" : "samurai",
        "typeLoader" : "fbx",
        "elementLink" : "assets/samurai/Samurai_Idle.fbx",
        "textured" : true,
        "texture" : {
            "links" : ["assets/samurai/UV Samurai.png"],
        },
        "animated" : true,
        "animation" : {
            "animationLinks" : ["assets/samurai/Samurai_Run.fbx"],
            "initAnimation" : 0,
        },
        "scale" : {"x" : 0.015, "y" : 0.015, "z" : 0.015},
        "position" : {"x" : 0, "y" : -9.4, "z" : 0},
        "rotation" : {"x" : 0, "y" : 0, "z" : 0},
    }, 1, 0, 1, 1);
    
    elements['demon'] = new Character({
        "name" : "demon",
        "typeLoader" : "fbx",
        "elementLink" : "assets/demon/Demon_Idle.fbx",
        "textured" : true,
        "texture" : {
            "links" : ["assets/demon/UV Demon.png"],
        },
        "animated" : true,
        "animation" : {
            "animationLinks" : ["assets/demon/Demon_Run.fbx"],
            "initAnimation" : 0,
        },
        "scale" : {"x" : 0.020, "y" : 0.020, "z" : 0.020},
        "position" : {"x" : 0, "y" : -9.4, "z" : 0},
        "rotation" : {"x" : 0, "y" : 0, "z" : 0},
    },1.2, 0, 1, 3);

    elements['zombie'] = new Character({
        "name" : "zombie",
        "typeLoader" : "fbx",
        "elementLink" : "assets/zombie/Zombie Idle.fbx",
        "textured" : true,
        "texture" : {
            "links" : ["assets/zombie/UVZombi.png"],
        },
        "animated" : true,
        "animation" : {
            "animationLinks" : ["assets/zombie/Zombie Walk.fbx"],
            "initAnimation" : 0,
        },
        "scale" : {"x" : 0.0015, "y" : 0.0015, "z" : 0.0015},
        "position" : {"x" : 0, "y" : -9.4, "z" : 0},
        "rotation" : {"x" : 0, "y" : 0, "z" : 0},
    },0.07, 0, 1, 0.3);

    elements['troll'] = new Character({
        "name" : "troll",
        "typeLoader" : "fbx",
        "elementLink" : "assets/troll/Troll_Idle.fbx",
        "textured" : true,
        "texture" : {
            "links" : ["assets/troll/UVTroll.png"],
        },
        "animated" : true,
        "animation" : {
            "animationLinks" : ["assets/troll/Troll_walking.fbx"],
            "initAnimation" : 0,
        },
        "scale" : {"x" : 0.020, "y" : 0.020, "z" : 0.020},
        "position" : {"x" : 0, "y" : -9.4, "z" : 0},
        "rotation" : {"x" : 0, "y" : 0, "z" : 0},
    },0.23, 0, 1, 3);

    elements['gazebo'] = new Element({
        "name" : "gazebo",
        "typeLoader" : "obj",
        "elementLink" : "assets/gazebo/gazebo.obj",
        "textured" : true,
        "texture" : {
            "links" : ["assets/gazebo/gazebo_diffuse.png"],
            "normal" : "assets/gazebo/gazebo_nmap.png",
        },
        "animated" : false,
        "scale" : {"x" : 1, "y" : 1, "z" : 1},
        "position" : {"x" : -39, "y" : -9.4, "z" : 87},
        "rotation" : {"x" : 0, "y" : 0, "z" : 0},
    });

    elements['orc'] = new Element({
        "name" : "orc",
        "typeLoader" : "fbx",
        "elementLink" : "assets/orc/Ork.FBX",
        "textured" : true,
        "texture" : {
            "links" : ["assets/orc/UV Orc.png"],
        },
        "animated" : false,
        "scale" : {"x" : 0.030, "y" : 0.030, "z" : 0.030},
        "position" : {"x" : 10, "y" : -9.4, "z" : 60},
        "rotation" : {"x" : 0, "y" : 0, "z" : 0},
    });

    elements['satellite'] = new Element({
        "name" : "satellite",
        "typeLoader" : "fbx",
        "elementLink" : "assets/satellite/Satellite.FBX",
        "textured" : true,
        "texture" : {
            "links" : ["assets/satellite/Satellite_AlbedoTransparency.png"],
            "emissive" : "assets/satellite/Satellite_low_Emissive.png",
            "metalness" : "assets/satellite/Satellite_MetallicSmoothness.png",
            "normal" : "assets/satellite/Satellite_Normal.png",
        },
        "animated" : false,
        "scale" : {"x" : 0.6, "y" : 0.6, "z" : 0.6},
        "position" : {"x" : 0, "y" : 1800, "z" : 500},
        "rotation" : {"x" : 0, "y" : 0, "z" : 0},
    });

    elements['table-tennis'] = new Element({
        "name" : "table-tennis",
        "typeLoader" : "obj",
        "elementLink" : "assets/table-tennis/Table Tennis Table.obj",
        "textured" : true,
        "texture" : {
            "links" : ["assets/table-tennis/Table Tennis Table_diffuse.png"],
        },
        "animated" : false,
        "scale" : {"x" : 7, "y" : 7, "z" : 7},
        "position" : {"x" : -190, "y" : -9.4, "z" : 0},
        "rotation" : {"x" : 0, "y" : 0, "z" : 0},
    });

    elements['wind-turbine'] = new Element({
        "name" : "wind-turbine",
        "typeLoader" : "fbx",
        "elementLink" : "assets/wind-turbine/Wind_turbine_001.fbx",
        "textured" : true,
        "texture" : {
            "links" : ["assets/wind-turbine/Wind_Turbine_001_color.png"],
        },
        "animated" : true,
        "animation" : {
            "initAnimation" : 0,
        },
        "scale" : {"x" : 0.04, "y" : 0.04, "z" : 0.04},
        "position" : {"x" : 0, "y" : -9.4, "z" : -400},
        "rotation" : {"x" : 0, "y" : 0, "z" : 0},
    });

    elements['camel'] = new Element({
        "name" : "camel",
        "typeLoader" : "fbx",
        "elementLink" : "assets/camel/Camel_low.FBX",
        "textured" : true,
        "texture" : {
            "links" : ["assets/camel/Camel_low_02 - Default_AlbedoTransparency.png"],
            "metalness" : "assets/camel/02 - Default_metallic.jpg",
            "normal" : "assets/camel/Camel_low_02 - Default_Normal.png",
            "roughness" : "assets/camel/02 - Default_roughness.jpg",
        },
        "animated" : false,
        "scale" : {"x" : 4, "y" : 4, "z" : 4},
        "position" : {"x" : 160, "y" : -9.4, "z" : 290},
        "rotation" : {"x" : 0, "y" : 0, "z" : 0},
    });

    elements['cottagge'] = new Element({
        "name" : "cottagge",
        "typeLoader" : "fbx",
        "elementLink" : "assets/cottage/cottage_fbx.fbx",
        "textured" : true,
        "texture" : {
            "links" : ["assets/cottage/cottage_diffuse.png"],
            "normal" : "assets/cottage/cottage_normal.png",
        },
        "animated" : false,
        "scale" : {"x" : 0.025, "y" : 0.025, "z" : 0.025},
        "position" : {"x" : -200, "y" : -10, "z" : -100},
        "rotation" : {"x" : 0, "y" : 0, "z" : 0},
    });

    elements['dragon'] = new Element({
        "name" : "dragon",
        "typeLoader" : "fbx",
        "elementLink" : "assets/dragon/Dragon_Baked_Actions_fbx_7.4_binary.fbx",
        "textured" : true,
        "texture" : {
            "links" : ["assets/dragon/textures/Dragon_ground_color.jpg"],
            "normal" : "assets/dragon/textures/Dragon_Nor.jpg",
        },
        "animated" : true,
        "animation" : {
            "initAnimation" : 2,
        },
        "scale" : {"x" : 0.015, "y" : 0.015, "z" : 0.015},
        "position" : {"x" : 250, "y" : -10, "z" : -100},
        "rotation" : {"x" : 0, "y" : 0, "z" : 0},
    });

    elements['bench_press'] = new Element({
        "name" : "bench_press",
        "typeLoader" : "fbx",
        "elementLink" : "assets/Low Poly Gym Pack/Bench Press/BenchPress.fbx",
        "textured" : false,
        "animated" : false,
        "scale" : {"x" : 0.06, "y" : 0.06, "z" : 0.06},
        "position" : {"x" : 15, "y" : -5, "z" : 0},
        "rotation" : {"x" : 0, "y" : 0, "z" : 0},
    });

    elements['dip_station'] = new Element({
        "name" : "dip_station",
        "typeLoader" : "fbx",
        "elementLink" : "assets/Low Poly Gym Pack/Dip Station/DipStation.fbx",
        "textured" : false,
        "animated" : false,
        "scale" : {"x" : 0.06, "y" : 0.06, "z" : 0.06},
        "position" : {"x" : 15, "y" : 1, "z" : 20},
        "rotation" : {"x" : 0, "y" : 0, "z" : 0},
    });

    elements['dumbbell'] = new Element({
        "name" : "dumbbell",
        "typeLoader" : "fbx",
        "elementLink" : "assets/Low Poly Gym Pack/Dumbbell/Dumbbell.fbx",
        "textured" : false,
        "animated" : false,
        "scale" : {"x" : 0.06, "y" : 0.06, "z" : 0.06},
        "position" : {"x" : 15, "y" : -9, "z" : 12},
        "rotation" : {"x" : 0, "y" : 0, "z" : 0},
    });

    elements['incline_bench_press'] = new Element({
        "name" : "incline_bench_press",
        "typeLoader" : "fbx",
        "elementLink" : "assets/Low Poly Gym Pack/Incline Bench Press/InclineBenchPress.fbx",
        "textured" : false,
        "animated" : false,
        "scale" : {"x" : 0.06, "y" : 0.06, "z" : 0.06},
        "position" : {"x" : 15, "y" : -4, "z" : -20},
        "rotation" : {"x" : 0, "y" : 0, "z" : 0},
    });

    elements['peck_deck'] = new Element({
        "name" : "peck_deck",
        "typeLoader" : "fbx",
        "elementLink" : "assets/Low Poly Gym Pack/Pec Deck Machine/PecDeckMachine.fbx",
        "textured" : false,
        "animated" : false,
        "scale" : {"x" : 0.06, "y" : 0.06, "z" : 0.06},
        "position" : {"x" : 45, "y" : 2.5, "z" : -20},
        "rotation" : {"x" : 0, "y" : Math.PI, "z" : 0},
    });

    elements['preacher_bench'] = new Element({
        "name" : "preacher_bench",
        "typeLoader" : "fbx",
        "elementLink" : "assets/Low Poly Gym Pack/Preacher Bench/PreacherBench.fbx",
        "textured" : false,
        "animated" : false,
        "scale" : {"x" : 0.06, "y" : 0.06, "z" : 0.06},
        "position" : {"x" : 45, "y" : -5.5, "z" : 0},
        "rotation" : {"x" : 0, "y" : Math.PI/2, "z" : 0},
    });

    elements['tricep_bar'] = new Element({
        "name" : "tricep_bar",
        "typeLoader" : "fbx",
        "elementLink" : "assets/Low Poly Gym Pack/Tricep Bar/TricepBar.fbx",
        "textured" : false,
        "animated" : false,
        "scale" : {"x" : 0.06, "y" : 0.06, "z" : 0.06},
        "position" : {"x" : 15, "y" : -9, "z" : 15},
        "rotation" : {"x" : 0, "y" : Math.PI/2, "z" : 0},
    });

    elements['pull_up_bar'] = new Element({
        "name" : "pull_up_bar",
        "typeLoader" : "fbx",
        "elementLink" : "assets/Low Poly Gym Pack/Wall Mounted Pull-up Bar/WallMountedPull-upBar.fbx",
        "textured" : false,
        "animated" : false,
        "scale" : {"x" : 0.06, "y" : 0.06, "z" : 0.06},
        "position" : {"x" : 15, "y" : -3, "z" : 35},
        "rotation" : {"x" : 0, "y" : 0, "z" : 0},
    });
}

var initVegetation = function(scene){
    for (let i = 0; i < 100; i+=1){
        let grass = new Element({
            "name" : "grass"+i,
            "typeLoader" : "fbx",
            "elementLink" : "assets/grass/High Grass.fbx",
            "textured" : true,
            "texture" : {
                "links" : ["assets/grass/Grass.png"],
            },
            "animated" : false,
            "scale" : {"x" : 0.13, "y" : 0.13, "z" : 0.13},
            "position" : {"x" : getRandom(-1000,1000), "y" : -10, "z" : getRandom(-1000,1000)},
            "rotation" : {"x" : 0, "y" : getRandom(0,Math.PI*2), "z" : 0},
        });
        grass.load(scene);
    }
}

var initStreetLight = function (scene, streetLights) {
    for (let i = 0; i < 30; i++){

    }
}

var getRandom = function (min, max) {
  return Math.random() * (max - min) + min;
}

export{
    redererInit, groundInit, initElements, initVegetation, initStreetLight
}