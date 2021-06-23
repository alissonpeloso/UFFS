var scene;
var camera;
var render;

var green = new THREE.Color(0,1,0);
var red = new THREE.Color(1,0,0);
var blue = new THREE.Color(0,0,1);

var criaCubo = function(){
    let geometria = new THREE.BoxGeometry(5,5,5);

    let materials = [
        new THREE.MeshBasicMaterial({color: green}),
        new THREE.MeshBasicMaterial({color: blue}),
        new THREE.MeshBasicMaterial({color: red}),
        new THREE.MeshBasicMaterial({color: green}),
        new THREE.MeshBasicMaterial({color: blue}),
        new THREE.MeshBasicMaterial({color: red}),
    ]

    let cubo = new THREE.Mesh(geometria, materials);
    scene.add(cubo);

    let cubo2 = new THREE.Mesh(geometria, materials);
    scene.add(cubo2);
    cubo2.position.y = 10;

    let cubo3 = new THREE.Mesh(geometria, materials);
    scene.add(cubo3);
    cubo3.position.x = 10;

    cubo.rotation.x = 0.5;
    cubo.rotation.y = 0.5;
}

var criaTorus = function (radius, tube, radialSegments, tubularSegments, x, y, z) {
    let geometry = new THREE.TorusGeometry( radius, tube, radialSegments, tubularSegments );
    let material = new THREE.MeshBasicMaterial( { color: green } );
    let torus = new THREE.Mesh( geometry, material );
    scene.add( torus );
    torus.position.x = x;
    torus.position.y = y;
    torus.position.z = z;
    torus.rotation.y = 0.5;
}

var criaCone = function (radius, height, radialSegments, x, y, z) { 
    const geometry = new THREE.ConeGeometry( radius, height, radialSegments );
    let materials = [
        new THREE.MeshBasicMaterial({color: green}),
        new THREE.MeshBasicMaterial({color: blue}),
        new THREE.MeshBasicMaterial({color: red}),
        new THREE.MeshBasicMaterial({color: green}),
        new THREE.MeshBasicMaterial({color: blue}),
        new THREE.MeshBasicMaterial({color: red}),
    ]
    const material = new THREE.MeshBasicMaterial( {color: 0xffff00} );
    const cone = new THREE.Mesh( geometry, materials );
    scene.add( cone );
    cone.position.x = x;
    cone.position.y = y;
    cone.position.z = z;
    cone.rotation.x = -0.5;
}

var criaCilindro = function (radius, radiusBotton, height, radialSegments, x, y, z) { 
    const geometry = new THREE.CylinderGeometry( radius, radiusBotton, height, radialSegments );
    let materials = [
        new THREE.MeshBasicMaterial({color: green}),
        new THREE.MeshBasicMaterial({color: blue}),
        new THREE.MeshBasicMaterial({color: red}),
        new THREE.MeshBasicMaterial({color: green}),
        new THREE.MeshBasicMaterial({color: blue}),
        new THREE.MeshBasicMaterial({color: red}),
    ]
    const cylinder = new THREE.Mesh( geometry, materials );
    scene.add( cylinder );
    cylinder.position.x = x;
    cylinder.position.y = y;
    cylinder.position.z = z;
    cylinder.rotation.x = 0.5;
}

var init = function (){
    scene = new THREE.Scene();
    camera = new THREE.PerspectiveCamera(40, window.innerWidth/window.innerHeight, 1, 100);

    render = new THREE.WebGLRenderer();
    render.setSize(window.innerWidth, window.innerHeight);
    document.body.appendChild(render.domElement);

    camera.position.z = 40;
    camera.position.y = 0;
    camera.position.x = 0;

    criaCubo();
    criaTorus(4,1,14,50,20,6,-5);
    criaCone(5, 7, 5, -10,5,5);
    criaCilindro(5, 5, 5, 15, -10,-6,5);

    render.render(scene, camera);
}

window.onload = init();