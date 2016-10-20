//
//  Particle.cpp
//  w04_Problem_C
//
//  Created by Danli Hu on 9/29/16.
//
//

#include "Particle.hpp"


Particle::Particle(){
    setup(0, 0, 0, 0);
    damping = 1.01;
}

void Particle::setup(float _x, float _y, float _imgWidth, float _imgHeight){
    vel.x = ofRandom(-0.5,0.5);
    vel.y = ofRandom(0.5,2);
    
    pos.x = _x + (ofGetWidth()/2 - _imgWidth/2);
    pos.y = _y + (ofGetHeight()/2 - _imgHeight/2);
    
    alpha = 255;
}

void Particle::update(){
    
    vel *= damping;
    pos += vel;
//    alpha -= ofRandom(10);
    
    float randomNum = ofGetHeight() - 10 + ofRandom(20);
    
    if(pos.y > randomNum){
        pos.y = randomNum;
    }
}

void Particle::draw(ofColor _color){
    ofSetColor(_color);
    ofDrawCircle(pos, 1);
}

void Particle::restart(float _x, float _y){
    pos.x = _x;
    pos.y = _y;
}

