class Form{
    geometry;
    direction_x;
    direction_y;
    velocity;

    constructor (geometry, direction_x, direction_y, velocity,){
        this.geometry = geometry;
        this.direction_x = direction_x;
        this.direction_y = direction_y;
        this.velocity = velocity;
    }

    changeDirectionX(){
        if (this.direction_x == 'left'){
            this.direction_x = 'right';
        }
        else if(this.direction_x == 'right'){
            this.direction_x = 'left';
        }
    }

    changeDirectionY(){
        if (this.direction_y == 'up'){
            this.direction_y = 'down';
        }
        else if(this.direction_y == 'down'){
            this.direction_y = 'up';
        }
    }

    changeColor(){
        if(Array.isArray(this.geometry.material)){
            this.geometry.material[0].color.setHex(hexadecimal_color());
            this.geometry.material[1].color.setHex(hexadecimal_color());
            this.geometry.material[2].color.setHex(hexadecimal_color());
        }
        else{
            this.geometry.material.color.setHex(hexadecimal_color());
        }
    }
}

function hexadecimal_color()
{
  return Math.floor(Math.random() * 0xFFFFFF);
}

var scene, camera, render;

var direction = {'up': 1, 'down': -1, 'right': 1, 'left': -1};
var forms = [];

var animation = function (){
	requestAnimationFrame(animation);

	forms.forEach(form => {
		form.geometry.position.x+= form.velocity*direction[form.direction_x];
        form.geometry.rotation.x += 0.03;
        form.geometry.rotation.y += 0.03;

        if(form.geometry.position.x > 33 || form.geometry.position.x < -33){
            form.changeDirectionX();
            form.changeColor();
        }

        form.geometry.position.y+= form.velocity*direction[form.direction_y];

        if(form.geometry.position.y > 15 || form.geometry.position.y < -15){
            form.changeDirectionY();
            form.changeColor();
        }
	});
	
    render.render(scene, camera);
}

var criaTorus = function (radius, tube, radialSegments, tubularSegments, x, y, z) {
    let geometry = new THREE.TorusGeometry( radius, tube, radialSegments, tubularSegments );
    let material = new THREE.MeshBasicMaterial({color: hexadecimal_color()});
    let torus = new THREE.Mesh( geometry, material);
    scene.add( torus );
    torus.position.x = x;
    torus.position.y = y;
    torus.position.z = z;

    return torus;
}

var criaCone = function (radius, height, radialSegments, x, y, z) { 
    const geometry = new THREE.ConeGeometry( radius, height, radialSegments );
    let materials = [
        new THREE.MeshBasicMaterial({color: hexadecimal_color()}),
        new THREE.MeshBasicMaterial({color: hexadecimal_color()}),
        new THREE.MeshBasicMaterial({color: hexadecimal_color()}), 
    ];
    const cone = new THREE.Mesh( geometry, materials);
    scene.add( cone );
    cone.position.x = x;
    cone.position.y = y;
    cone.position.z = z;

    return cone;
}

var init = function (){
    scene = new THREE.Scene();
    camera = new THREE.PerspectiveCamera(40, window.innerWidth/window.innerHeight, 1, 100);

    render = new THREE.WebGLRenderer();
    render.setSize(window.innerWidth, window.innerHeight);
    document.body.appendChild(render.domElement);

    camera.position.z = 50;
    camera.position.y = 0;
    camera.position.x = 0;

    forms[0] = new Form(criaTorus(4, 1, 14, 50, 20, 6, -5),'left', 'up', 0.3);
    forms[1] = new Form(criaCone(4, 7, 50, -10, 5, 5), 'right', 'down', 0.3);

    console.log(forms);

    animation();

    render.render(scene, camera);
}

window.onload = init();