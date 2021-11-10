import * as THREE from '../threejs/three.module.js';

class Texture{
    constructor(texture){
        // texture = {
        //     "links" : ["url_textura1","url_textura2","url_textura1"],
        //     "displacement" : "url_displacement",
        //     "emissive" : "url_emissive",
        //     "metalness" : "url_metalness",
        //     "normal" : "url_normal",
        //     "roughness" : "url_roughness",
        //     "alpha" : "url_alpha",
        //     "bump" : "url_bump" 
        // }
        
        this.material = new THREE.MeshStandardMaterial();
        this.links = texture.links;
        this.displacement = texture.displacement;
        this.emissive = texture.emissive;
        this.metalness = texture.metalness;
        this.normal = texture.normal;
        this.roughness = texture.roughness;
        this.alpha = texture.alpha;
        this.bump = texture.bump;
    }

    async load(){
        var textureLoader = new THREE.TextureLoader();

        this.material.map = textureLoader.load(this.links[0]);
        if (this.displacement) {
            this.material.displacementMap = textureLoader.load(this.displacement);
        }
        if (this.normal) {
            this.material.normalMap = textureLoader.load(this.normal);
        }
        if (this.metalness) {
            this.material.metalnessMap = textureLoader.load(this.metalness);
        }
        if (this.roughness) {
            this.material.roughnessMap = textureLoader.load(this.roughness);
        }
        if (this.emissive) {
            this.material.emissiveMap = textureLoader.load(this.emissive);
        }
        if (this.alpha) {
            this.material.alphaMap = textureLoader.load(this.alpha);
        }
        if (this.bump) {
            this.material.bumpMap = textureLoader.load(this.bump);
        }
        return;
    }
}

export {Texture};