import { FBXLoader } from "../loaders/FBXLoader.js"
import { OBJLoader } from "../loaders/OBJLoader.js"
import * as THREE from '../threejs/three.module.js';
import { Texture } from "./texture.js";
import { Animation } from "./animation.js";

class Element{
    constructor(json){
        // json = {
        //     "name" : "objName",
        //     "typeLoader" : "fbx/obj",
        //     "elementLink" : "url_element",
        //     "textured" : "boolean",
        //     "texture" : "texture_obj",
        //     "animated" : "boolean",
        //     "animation" : "animation_obj",
        //     "currentAnimation" : "int"
        //     "scale" : "scale_obj",
        //     "position" : "position_obj",
        //     "rotation" : "rotation_obj",
        // }
               
        this.name = json.name; //string
        this.typeLoader = json.typeLoader //string
        this.elementLink = json.elementLink //string

        //Texture
        this.textured = json.textured; //boolean
        if(this.textured){
            this.Texture = new Texture(json.texture);
        }

        //Animation
        this.animated = json.animated; //boolean
        if(this.animated){
            this.Animation = new Animation(json.animation);
        }
        
        //Scale
        this.scale = json.scale;

        //Position
        this.position = json.position;

        //Rotation
        this.rotation = json.rotation;

        this.mesh = new THREE.Mesh(); //object THREE.Mesh
        this.loaded = false; //boolean

        this.box;
    }

    load(scene){
        var loader;
        var self = this;
        switch (this.typeLoader.toUpperCase()) {
            case 'FBX':
                loader = new FBXLoader();
                break;
            case 'OBJ':
                loader = new OBJLoader();
                break;
            default:
                console.log("ERROR");
        }
        if(self.textured){
            this.Texture.load();
        }

        return loader.loadAsync(this.elementLink).then((obj) => {
            obj.traverse(
                function(child){
                    if (child instanceof THREE.Mesh){
                        if(self.textured){
                            child.material = self.Texture.material;
                        }
                        child.castShadow = true;
                        child.receiveShadow = true;
                        
                    }
                }
            );
            self.mesh = obj;

            //set scale
            obj.scale.set(self.scale.x, self.scale.y, self.scale.z);

            //set position
            obj.position.set(self.position.x, self.position.y, self.position.z);

            //set rotation
            obj.rotation.set(self.rotation.x, self.rotation.y, self.rotation.z);

            obj.name = self.name;

            this.box = new THREE.Box3().setFromObject(obj);

            scene.add(obj);  

            if(self.animated){
                self.Animation.load(obj);
            }

            console.log(self.name+" carregado com sucesso!");
            self.loaded = true;
        }).catch(err => {
            console.log("Erro ao carregar "+self.name+": "+error);
        })
    }

}

export {Element};