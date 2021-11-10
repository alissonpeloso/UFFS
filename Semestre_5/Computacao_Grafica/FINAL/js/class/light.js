import * as THREE from '../threejs/three.module.js';

class Light{
    constructor(json){
        this.position = json.position;
        this.color = json.color;
        this.intesity = json.intesity;
        this.type = json.type;
        this.skyColor = json.skyColor; //HemisphereLIght
        this.groundColor = json.groundColor; //HemisphereLIght
        this.distance = json.distance; //pointLight
        this.decay = json.decay; //pointLight
        this.angle = json.angle; //spotLight
        this.penumbra = json.penumbra; //spotLight
    }

    async load(scene){
        var light;

        switch(this.type.toUpperCase()){
            case 'AMBIENTLIGHT':
                light = new THREE.AmbientLight(this.color,this.intesity);
                break;
            case 'DIRECTIONALLIGHT':
                light = new THREE.DirectionalLight(this.color, this.intesity);
                light.position.set(this.position.x, this.position.y, this.position.z);
                light.castShadow = true;

                break;
            case 'HEMISPHERELIGHT':
                light = new THREE.HemisphereLight(this.skyColor, this.groundColor, this.intesity);
                break;
            case 'POINTLIGHT':
                light = new THREE.PointLight(this.color, this.intesity, this.distance, this.decay);
                light.position.set(this.position.x, this.position.y, this.position.z);
                light.castShadow = true;

                break;
            case 'SPOTLIGHT':
                light = new THREE.SpotLight(this.color, this.intesity, this.distance, this.angle, this.penumbra, this.decay);
                light.position.set(this.position.x, this.position.y, this.position.z);
                light.castShadow = true;

                break;
            default:
                console.log("ERROR");
        }

        this.mesh = light;
        scene.add(this.mesh);
        return;
    }

}

export { Light }