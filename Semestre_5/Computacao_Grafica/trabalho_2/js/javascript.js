var Monster = new Object();
Monster.body = new THREE.Group();
Monster.head;
Monster.torso;
Monster.arms;
Monster.legs;

var anchors = {
    'r_shoulder': new THREE.Group(),
    'l_shoulder': new THREE.Group(),
    'r_elbow': new THREE.Group(),
    'l_elbow': new THREE.Group(),
    'r_thigh': new THREE.Group(),
    'l_thigh': new THREE.Group(),
    'r_knee': new THREE.Group(),
    'l_knee': new THREE.Group(),
}

var scene, camera, render, light;

var animation = function (){
    requestAnimationFrame(animation);

    // Monster.body.rotation.y += 0.05;

    render.render(scene, camera);
}

var createMonster = function () {
    // Head
    Monster.head = new THREE.Mesh( new THREE.TorusKnotGeometry( 3, 1, 100, 16 ), new THREE.MeshBasicMaterial({color: 0xffff00}));
    Monster.head.position.y += 15;

    // Torso
    Monster.torso = new THREE.Group();
    Monster.torso.add(new THREE.Mesh( new THREE.CylinderGeometry( 6, 6, 20, 32 ), new THREE.MeshBasicMaterial({color: 0x00ff00})));
    Monster.torso.children[0].rotation.z += Math.PI/2;
    Monster.torso.children[0].position.y += 2; 
    Monster.torso.add(new THREE.Mesh( new THREE.CylinderGeometry( 6, 3, 7, 32 ), new THREE.MeshBasicMaterial({color: 0x00ff00})));
    Monster.torso.children[1].position.y -= 9;
    Monster.torso.add(new THREE.Mesh( new THREE.SphereGeometry( 6, 32, 32 ), new THREE.MeshBasicMaterial({color: 0xff0000})));
    Monster.torso.children[2].position.y -= 1;

    // Arms
    Monster.arms = new THREE.Group();
    Monster.arms.add(new THREE.Mesh( new THREE.SphereGeometry( 5, 32, 32 ), new THREE.MeshBasicMaterial({color: 0xff0000})));
    Monster.arms.children[0].position.x -= 11;
    Monster.arms.children[0].position.y += 3;
    Monster.arms.children[0].name = 'r_shoulder';

    Monster.arms.add(new THREE.Mesh( new THREE.SphereGeometry( 5, 32, 32 ), new THREE.MeshBasicMaterial({color: 0xff0000})));
    Monster.arms.children[1].position.x += 11;
    Monster.arms.children[1].position.y += 3;
    Monster.arms.children[1].name = 'l_shoulder';

    Monster.arms.add(new THREE.Mesh( new THREE.CylinderGeometry( 3.7, 2.5, 5, 32  ), new THREE.MeshBasicMaterial({color: 0x0000ff})));
    Monster.arms.children[2].position.y -= 5;
    Monster.arms.children[2].name = 'r_arm';

    Monster.arms.add(new THREE.Mesh( new THREE.CylinderGeometry( 3.7, 2.5, 5, 32  ), new THREE.MeshBasicMaterial({color: 0x0000ff})));
    Monster.arms.children[3].position.y -= 5;
    Monster.arms.children[3].name = 'l_arm';

    Monster.arms.add(new THREE.Mesh( new THREE.SphereGeometry( 2.5, 32, 32 ), new THREE.MeshBasicMaterial({color: 0xff0000})));
    Monster.arms.children[4].position.y -= 3;
    Monster.arms.children[4].name = 'r_elbow';

    Monster.arms.add(new THREE.Mesh( new THREE.SphereGeometry( 2.5, 32, 32 ), new THREE.MeshBasicMaterial({color: 0xff0000})));
    Monster.arms.children[5].position.y -= 3;
    Monster.arms.children[5].name = 'l_elbow';

    Monster.arms.add(new THREE.Mesh( new THREE.CylinderGeometry( 3, 1.5, 7, 32  ), new THREE.MeshBasicMaterial({color: 0x0000ff})));
    Monster.arms.children[6].position.y -= 5;
    Monster.arms.children[6].name = 'r_forearm';

    Monster.arms.add(new THREE.Mesh( new THREE.CylinderGeometry( 3, 1.5, 7, 32  ), new THREE.MeshBasicMaterial({color: 0x0000ff})));
    Monster.arms.children[7].position.y -= 5;
    Monster.arms.children[7].name = 'l_forearm';

    Monster.arms.add(new THREE.Mesh( new THREE.TetrahedronGeometry( 4, 0 ), new THREE.MeshBasicMaterial({color: 0xffff00})));
    Monster.arms.children[8].position.y -= 5;
    Monster.arms.children[8].name = 'r_hand';

    Monster.arms.add(new THREE.Mesh( new THREE.TetrahedronGeometry( 4, 0 ), new THREE.MeshBasicMaterial({color: 0xffff00})));
    Monster.arms.children[9].position.y -= 5;
    Monster.arms.children[9].name = 'l_hand';

    // Legs
    Monster.legs = new THREE.Group();
    Monster.legs.add(new THREE.Mesh( new THREE.CylinderGeometry( 4, 7, 4, 32  ), new THREE.MeshBasicMaterial({color: 0x5f0fff})));
    Monster.legs.children[0].position.y -= 14;
    Monster.legs.children[0].name = 'wais';

    Monster.legs.add(new THREE.Mesh( new THREE.SphereGeometry( 3, 32, 32 ), new THREE.MeshBasicMaterial({color: 0xff0000})));
    Monster.legs.children[1].position.x += 4;
    Monster.legs.children[1].position.y -= 17;
    Monster.legs.children[1].name = 'l_pthigh';

    Monster.legs.add(new THREE.Mesh( new THREE.SphereGeometry( 3, 32, 32 ), new THREE.MeshBasicMaterial({color: 0xff0000})));
    Monster.legs.children[2].position.x -= 4;
    Monster.legs.children[2].position.y -= 17;
    Monster.legs.children[2].name = 'r_pthigh';

    Monster.legs.add(new THREE.Mesh( new THREE.CylinderGeometry( 3.5, 2.5, 9, 32  ), new THREE.MeshBasicMaterial({color: 0x5f0fff})));
    Monster.legs.children[3].position.y -= 4;
    Monster.legs.children[3].name = 'l_thigh';

    Monster.legs.add(new THREE.Mesh( new THREE.CylinderGeometry( 3.5, 2.5, 9, 32  ), new THREE.MeshBasicMaterial({color: 0x5f0fff})));
    Monster.legs.children[4].position.y -= 4;
    Monster.legs.children[4].name = 'r_thigh';

    Monster.legs.add(new THREE.Mesh( new THREE.SphereGeometry( 2, 32, 32 ), new THREE.MeshBasicMaterial({color: 0xff0000})));
    Monster.legs.children[5].position.y -= 5;
    Monster.legs.children[5].name = 'l_knee';

    Monster.legs.add(new THREE.Mesh( new THREE.SphereGeometry( 2, 32, 32 ), new THREE.MeshBasicMaterial({color: 0xff0000})));
    Monster.legs.children[6].position.y -= 5;
    Monster.legs.children[6].name = 'r_knee';
    
    Monster.legs.add(new THREE.Mesh( new THREE.CylinderGeometry( 3, 2, 10, 32  ), new THREE.MeshBasicMaterial({color: 0x5f0fff})));
    Monster.legs.children[7].position.y -= 5;
    Monster.legs.children[7].name = 'l_calf';

    Monster.legs.add(new THREE.Mesh( new THREE.CylinderGeometry( 3, 2, 10, 32  ), new THREE.MeshBasicMaterial({color: 0x5f0fff})));
    Monster.legs.children[8].position.y -= 5;
    Monster.legs.children[8].name = 'r_calf';
    
    Monster.legs.add(new THREE.Mesh( new THREE.BoxGeometry( 4, 2, 8 ), new THREE.MeshBasicMaterial({color: 0xffff00})));
    Monster.legs.children[9].position.y -= 5;
    Monster.legs.children[9].position.z += 2;
    Monster.legs.children[9].name = 'r_foot';

    Monster.legs.add(new THREE.Mesh( new THREE.BoxGeometry( 4, 2, 8 ), new THREE.MeshBasicMaterial({color: 0xffff00})));
    Monster.legs.children[10].position.y -= 5;
    Monster.legs.children[10].position.z += 2;
    Monster.legs.children[10].name = 'l_foot';

    // SET ANCHORS

    //right arm
    Monster.arms.getObjectByName('r_shoulder').add(anchors.r_shoulder);
    anchors.r_shoulder.add(Monster.arms.getObjectByName('r_arm'));

    Monster.arms.getObjectByName('r_arm').add(Monster.arms.getObjectByName('r_elbow'));

    Monster.arms.getObjectByName('r_elbow').add(anchors.r_elbow);
    anchors.r_elbow.add(Monster.arms.getObjectByName('r_forearm'));

    Monster.arms.getObjectByName('r_forearm').add(Monster.arms.getObjectByName('r_hand'));

    //left arm
    Monster.arms.getObjectByName('l_shoulder').add(anchors.l_shoulder);
    anchors.l_shoulder.add(Monster.arms.getObjectByName('l_arm'));

    Monster.arms.getObjectByName('l_arm').add(Monster.arms.getObjectByName('l_elbow'));

    Monster.arms.getObjectByName('l_elbow').add(anchors.l_elbow);
    anchors.l_elbow.add(Monster.arms.getObjectByName('l_forearm'));

    Monster.arms.getObjectByName('l_forearm').add(Monster.arms.getObjectByName('l_hand'));

    //right leg
    Monster.legs.getObjectByName('r_pthigh').add(anchors.r_thigh);
    anchors.r_thigh.add(Monster.legs.getObjectByName('r_thigh'));

    Monster.legs.getObjectByName('r_thigh').add(Monster.legs.getObjectByName('r_knee'));

    Monster.legs.getObjectByName('r_knee').add(anchors.r_knee);
    anchors.r_knee.add(Monster.legs.getObjectByName('r_calf'));

    Monster.legs.getObjectByName('r_calf').add(Monster.legs.getObjectByName('r_foot'));

    //left leg
    Monster.legs.getObjectByName('l_pthigh').add(anchors.l_thigh);
    anchors.l_thigh.add(Monster.legs.getObjectByName('l_thigh'));

    Monster.legs.getObjectByName('l_thigh').add(Monster.legs.getObjectByName('l_knee'));

    Monster.legs.getObjectByName('l_knee').add(anchors.l_knee);
    anchors.l_knee.add(Monster.legs.getObjectByName('l_calf'));

    Monster.legs.getObjectByName('l_calf').add(Monster.legs.getObjectByName('l_foot'));

    Monster.body.add(Monster.head);
    Monster.body.add(Monster.torso);
    Monster.body.add(Monster.arms);
    Monster.body.add(Monster.legs);

    Monster.body.position.y += 10;
}

var init = function (){
    scene = new THREE.Scene();
    camera = new THREE.PerspectiveCamera(80, window.innerWidth/window.innerHeight, 1, 100);

    render = new THREE.WebGLRenderer();
    render.setSize(window.innerWidth, window.innerHeight);
    document.body.appendChild(render.domElement);

    camera.position.z = 50;
    camera.position.y = 0;
    camera.position.x = 0; 

    createMonster();

    scene.add(Monster.body);

    animation();

    render.render(scene, camera);

    document.addEventListener('keydown', onKeyDown);
    document.addEventListener('keypress', onKeyPress);
}

var onKeyPress = function (e){
    //left arm control
    if(e.keyCode == 119 && anchors.l_shoulder.rotation.x > -3.14){ //w
        anchors.l_shoulder.rotation.x -= 0.05;
    }
    if(e.keyCode == 87 && anchors.l_shoulder.rotation.x < 0.01){ //shift+w
        anchors.l_shoulder.rotation.x += 0.05;
    }
    if(e.keyCode == 113 && anchors.l_shoulder.rotation.z < 1.85){ //q
        anchors.l_shoulder.rotation.z += 0.05;
    }
    if(e.keyCode == 81 && anchors.l_shoulder.rotation.z > 0){ //shift+q
        anchors.l_shoulder.rotation.z -= 0.05;
    }
    if(e.keyCode == 116 && anchors.l_elbow.rotation.x > -2.2){ //t
        anchors.l_elbow.rotation.x -= 0.05;
    }
    if(e.keyCode == 84 && anchors.l_elbow.rotation.x < 0){ //shift+t
        anchors.l_elbow.rotation.x += 0.05;
    }

    //right arm control
    if(e.keyCode == 101 && anchors.r_shoulder.rotation.x > -3.14){ //e
        anchors.r_shoulder.rotation.x -= 0.05;
    }
    if(e.keyCode == 69 && anchors.r_shoulder.rotation.x < 0.01){ //shift+e
        anchors.r_shoulder.rotation.x += 0.05;
    }
    if(e.keyCode == 114 && anchors.r_shoulder.rotation.z > -1.85){ //r
        anchors.r_shoulder.rotation.z -= 0.05;
    }
    if(e.keyCode == 82 && anchors.r_shoulder.rotation.z < 0){ //shift+r
        anchors.r_shoulder.rotation.z += 0.05;
    }
    if(e.keyCode == 121 && anchors.r_elbow.rotation.x > -2.2){ //y
        anchors.r_elbow.rotation.x -= 0.05;
    }
    if(e.keyCode == 89 && anchors.r_elbow.rotation.x < 0){ //shift+y
        anchors.r_elbow.rotation.x += 0.05;
    }

    //left leg control
    if(e.keyCode == 115 && anchors.l_thigh.rotation.x > -1.5){ //s
        anchors.l_thigh.rotation.x -= 0.05;
    }
    if(e.keyCode == 83 && anchors.l_thigh.rotation.x < 1.5){ //shift+s
        anchors.l_thigh.rotation.x += 0.05;
    }
    if(e.keyCode == 97 && anchors.l_thigh.rotation.z < 1.5){ //a
        anchors.l_thigh.rotation.z += 0.05;
    }
    if(e.keyCode == 65 && anchors.l_thigh.rotation.z > 0){ //shift+a
        anchors.l_thigh.rotation.z -= 0.05;
    }
    if(e.keyCode == 103 && anchors.l_knee.rotation.x < 2.5){ //g
        anchors.l_knee.rotation.x += 0.05;
    }
    if(e.keyCode == 71 && anchors.l_knee.rotation.x > 0){ //shift+g
        anchors.l_knee.rotation.x -= 0.05;
    }

    //right arm control
    if(e.keyCode == 100 && anchors.r_thigh.rotation.x > -1.5){ //d
        anchors.r_thigh.rotation.x -= 0.05;
    }
    if(e.keyCode == 68 && anchors.r_thigh.rotation.x < 1.5){ //shift+d
        anchors.r_thigh.rotation.x += 0.05;
    }
    if(e.keyCode == 102 && anchors.r_thigh.rotation.z > -1.5){ //f
        anchors.r_thigh.rotation.z -= 0.05;
    }
    if(e.keyCode == 70 && anchors.r_thigh.rotation.z < 0){ //shift+f
        anchors.r_thigh.rotation.z += 0.05;
    }
    if(e.keyCode == 104 && anchors.r_knee.rotation.x < 2.5){ //h
        anchors.r_knee.rotation.x += 0.05;
    }
    if(e.keyCode == 72 && anchors.r_knee.rotation.x > 0){ //shift+h
        anchors.r_knee.rotation.x -= 0.05;
    }
}

var onKeyDown = function (e){
	// console.log(e.keyCode);

	if (e.keyCode == 37){ //tecla left
        Monster.body.rotation.y -= 0.1;
	}
    if (e.keyCode == 39){ //tecla right
		Monster.body.rotation.y += 0.1;
	}
    if (e.keyCode == 38){ //tecla up
		Monster.body.rotation.x -= 0.1;
	}
    if (e.keyCode == 40){ //tecla down
		Monster.body.rotation.x += 0.1;
	}

    render.render(scene, camera);
}

window.onload = init();