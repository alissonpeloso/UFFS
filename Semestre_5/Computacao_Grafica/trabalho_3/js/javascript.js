var scene, camera, render, light, elements = new Array(), anchors = new Array();

var createGUI = function(){
    const gui = new dat.GUI();

    paramGUI = {
        jaguarColor : 0xc78e36,
        jaguarRotation : 0,
        chameleonColor : 0x3b887e,
        chameleonRotation : 0,
        ratColor : 0x65544c,
        ratRotation : -Math.PI/2,
        rhinocerosColor : 0xd9d9d9,
        rhinocerosRotation : 0,
        pandaColor : 0xdedede,
        pandaRotation : 0,
        squirrelColor : 0x272315,
        squirrelRotation : 0,
        vision : "jaguar"
    }

    //jaguar
    let jaguar = gui.addFolder("Jaguar");
    let jaguarColor = jaguar.addColor(paramGUI, 'jaguarColor').name("Color");
    jaguarColor.onChange(function(param){
		elements["jaguar"].traverse(
			function (child){
				if (child instanceof THREE.Mesh){
					child.material = new THREE.MeshStandardMaterial(
                        {color: new THREE.Color(param)}
                    );
				}
			}
		);
    });
    let jaguarRotation = jaguar.add(paramGUI, 'jaguarRotation').min(-Math.PI).max(Math.PI).step(0.2).name("Rotation");
	jaguarRotation.onChange(function(param){
		elements["jaguar"].rotation.y = param;
	});

    //chameleon
    let chameleon = gui.addFolder("Chameleon");
    let chameleonColor = chameleon.addColor(paramGUI, 'chameleonColor').name("Color");
    chameleonColor.onChange(function(param){
		elements["chameleon"].traverse(
			function (child){
				if (child instanceof THREE.Mesh){
					child.material = new THREE.MeshStandardMaterial(
                        {color: new THREE.Color(param)}
                    );
				}
			}
		);
    });
    let chameleonRotation = chameleon.add(paramGUI, 'chameleonRotation').min(-Math.PI).max(Math.PI).step(0.2).name("Rotation");
	chameleonRotation.onChange(function(param){
		elements["chameleon"].rotation.y =  param;
	});

    //rat
    let rat = gui.addFolder("Rat");
    let ratColor = rat.addColor(paramGUI, 'ratColor').name("Color");
    ratColor.onChange(function(param){
		elements["rat"].traverse(
			function (child){
				if (child instanceof THREE.Mesh){
					child.material = new THREE.MeshStandardMaterial(
                        {color: new THREE.Color(param)}
                    );
				}
			}
		);
    });
    let ratRotation = rat.add(paramGUI, 'ratRotation').min(-Math.PI-Math.PI/2).max(Math.PI-Math.PI/2).step(0.2).name("Rotation");
	ratRotation.onChange(function(param){
		elements["rat"].rotation.y =  param;
	});

    //rhinoceros
    let rhinoceros = gui.addFolder("Rhinoceros");
    let rhinocerosColor = rhinoceros.addColor(paramGUI, 'rhinocerosColor').name("Color");
    rhinocerosColor.onChange(function(param){
		elements["rhino"].traverse(
			function (child){
				if (child instanceof THREE.Mesh){
					child.material = new THREE.MeshStandardMaterial(
                        {color: new THREE.Color(param)}
                    );
				}
			}
		);
    });
    let rhinocerosRotation = rhinoceros.add(paramGUI, 'rhinocerosRotation').min(-Math.PI).max(Math.PI).step(0.2).name("Rotation");
	rhinocerosRotation.onChange(function(param){
		elements["rhino"].rotation.y =  param;
	});

    //panda
    let panda = gui.addFolder("Panda");
    let pandaColor = panda.addColor(paramGUI, 'pandaColor').name("Color");
    pandaColor.onChange(function(param){
		elements["panda"].traverse(
			function (child){
				if (child instanceof THREE.Mesh){
					child.material = new THREE.MeshStandardMaterial(
                        {color: new THREE.Color(param)}
                    );
				}
			}
		);
    });
    let pandaRotation = panda.add(paramGUI, 'pandaRotation').min(-Math.PI).max(Math.PI).step(0.2).name("Rotation");
	pandaRotation.onChange(function(param){
		elements["panda"].rotation.y =  param;
	});

    //squirrel
    let squirrel = gui.addFolder("Squirrel");
    let squirrelColor = squirrel.addColor(paramGUI, 'squirrelColor').name("Color");
    squirrelColor.onChange(function(param){
		elements["squirrel"].traverse(
			function (child){
				if (child instanceof THREE.Mesh){
					child.material = new THREE.MeshStandardMaterial(
                        {color: new THREE.Color(param)}
                    );
				}
			}
		);
    });
    let squirrelRotation = squirrel.add(paramGUI, 'squirrelRotation').min(-Math.PI).max(Math.PI).step(0.2).name("Rotation");
	squirrelRotation.onChange(function(param){
		elements["squirrel"].rotation.y =  param;
	});

    //vision
    let options = ["jaguar", "chameleon", "rat", "rhino", "panda", "squirrel"];
    let vision = gui.addFolder("Vision");
    let select = vision.add(paramGUI, 'vision').options(options).name("Select");
	select.onChange(function(param){
        if (param == "jaguar"){
			camera.rotation.y = 0;
		}
        else if (param == "chameleon"){
			camera.rotation.y = Math.PI*2/6;
		}
        else if (param == "rat"){
			camera.rotation.y = Math.PI*2/6*2;
		}
        else if (param == "rhino"){
			camera.rotation.y = Math.PI*2/6*3;
		}
        else if (param == "panda"){
			camera.rotation.y = Math.PI*2/6*4;
		}
        else if (param == "squirrel"){
			camera.rotation.y = Math.PI*2/6*5;
		}
	});

    gui.open();
}

var loadObject = function(link, initial_color, initial_position, initial_scale, initial_rotation, anchor_rotation, name){
    let objLoader = new THREE.OBJLoader();

    objLoader.load(
        link,
        function(obj){
            obj.traverse(
                function(child){
                    if (child instanceof THREE.Mesh){
                        child.material = new THREE.MeshStandardMaterial(
                            {color: initial_color}
                        )
                    }
                }
            );

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

            anchors[name] = new THREE.Group();
            
            anchors[name].add(elements[name]);
            scene.add(anchors[name]);
            
            anchors[name].position.x = camera.position.x;
            anchors[name].position.y = camera.position.y;
            anchors[name].position.z = camera.position.z;
            
            anchors[name].rotation.x = anchor_rotation.x;
            anchors[name].rotation.y = anchor_rotation.y;
            anchors[name].rotation.z = anchor_rotation.z;

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
	spot.position.set(0,100,10);
	scene.add(spot);
}

var animation = function (){
    requestAnimationFrame(animation);

    render.render(scene, camera);
}

var init = function (){
    scene = new THREE.Scene();

	scene.background = new THREE.Color(0x00bfff);
    let ground = new THREE.Mesh(new THREE.PlaneBufferGeometry(2000,2000),new THREE.MeshStandardMaterial({color: 0x7cfc00}));
	ground.rotation.x = -Math.PI/2;
	ground.position.y-=10;
	scene.add(ground);

    camera = new THREE.PerspectiveCamera(50, window.innerWidth/window.innerHeight, 1, 100);

    render = new THREE.WebGLRenderer();
    render.setSize(window.innerWidth, window.innerHeight);
    document.body.appendChild(render.domElement);

    camera.position.x = 0;
    camera.position.y = 0;
    camera.position.z = 20;

    createGUI();

    ilumination();

    var positions = Array(), scales = Array(), rotations = Array(), anchor_rotations = Array();

    var r_anchor = 0;
    for(let i = 0; i < 6; i++){
        positions[i] = {x : 0, y : -5, z : -15};

        scales[i] = {x : 1, y : 1, z : 1};

        rotations[i] = {x : 0, y : 0, z : 0};

        anchor_rotations[i] = {x : 0, y : r_anchor, z : 0};

        r_anchor += Math.PI*2/6;
    }

    scales[1] = {x : 0.3, y : 0.3, z : 0.3}
    scales[2] = {x : 0.8, y : 0.8, z : 0.8}
    rotations[2] = {x : 0, y : -Math.PI/2, z : 0}
    scales[3] = {x : 2, y : 2, z : 2}
    scales[4] = {x : 1.3, y : 1.3, z : 1.3}
    scales[5] = {x : 0.4, y : 0.4, z : 0.4}
    
    loadObject("assets/jaguar/Jaguar.obj",0xc78e36, positions[0], scales[0], rotations[0], anchor_rotations[0], "jaguar");

    loadObject("assets/chameleon/Chameleon.obj",0x3b887e, positions[1], scales[1], rotations[1], anchor_rotations[1], "chameleon");

    loadObject("assets/rat/Rat.obj",0x65544c, positions[2], scales[2], rotations[2], anchor_rotations[2], "rat");

    loadObject("assets/rhinoceros/Rhino.obj",0xd9d9d9, positions[3], scales[3], rotations[3], anchor_rotations[3], "rhino");

    loadObject("assets/panda/Panda.obj",0xdedede, positions[4], scales[4], rotations[4], anchor_rotations[4], "panda");

    loadObject("assets/squirrel/HI.OBJ",0x272315, positions[5], scales[5], rotations[5], anchor_rotations[5], "squirrel");

    animation();

    
    


    render.render(scene, camera);
}

window.onload = this.init();