import { FBXLoader } from "../loaders/FBXLoader.js"
import * as THREE from '../threejs/three.module.js';

class Animation{
    constructor(json){
        // json = {
        //     "animationLinks" : ["url1, url2, url3"],
        //     "initAnimation" : "int",
        // };
        
        this.animationLinks = json.animationLinks;
        this.animationArray = new Array();
        this.initAnimation = json.initAnimation;
        this.currentAnimation;
        this.mixer;
        return;
    }

    load(element){
        const fbxLoader = new FBXLoader();
        this.mixer = new THREE.AnimationMixer(element);
        this.animationArray.push(this.mixer.clipAction(element.animations[0]));
        this.currentAnimation = null;


        if(this.animationLinks){
            if(this.animationLinks.length > 0){
                this.animationLinks.forEach(animationLink => {
                    var self = this;
                    fbxLoader.load(
                        animationLink,
                        function (obj){
                            self.animationArray.push(self.mixer.clipAction(obj.animations[0]));
                        },
                        function(loading){
    
                        },
                        function (error) {  
                            console.log("Erro ao carregar:"+animationLink+": "+error);
                        }
                    )
                });
            }
        }
        else {
            if(element.animations.length > 1){
                for (let index = 1; index < element.animations.length; index++) {
                    this.animationArray.push(this.mixer.clipAction(element.animations[index]));
                }
            }
        }
        this.changeAnimation(this.initAnimation);
    }

    changeAnimation(newAnimation) {
        if (newAnimation != this.currentAnimation && this.animationArray[newAnimation]){
            let prevAnimation = this.currentAnimation;
            this.currentAnimation = newAnimation;
            this.animationArray[newAnimation].reset();
            if(prevAnimation != null){
                this.animationArray[prevAnimation].stop();
            }
            this.animationArray[newAnimation].play();
        }
    }
}

export { Animation }