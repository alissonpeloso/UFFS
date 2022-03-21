import { Element } from "./element.js";
import * as THREE from '../threejs/three.module.js';

class Character extends Element{

    constructor(json, velocity, idle, walking, height) {
        super(json);
        this.velocity = velocity;
        this.idle = idle;
        this.walking = walking;
        this.height = height;
    }
}

export {Character}