//
//  Firework.cpp
//  w03_Problem_A_Fireworks
//
//  Created by Danli Hu on 9/21/16.
//
//

#include "Firework.hpp"

void Firework::start(){
    pos.x = ofGetWidth()/2;
    pos.y = 50;
    
//    startingPos.x = pos.x;
//    startingPos.y = pos.y;
    
    vel.x = ofRandom(-1.2,1.2);
    vel.y = ofRandom(-1,1);
    
    acc.y = ofRandom(0,0.01);
    
    alpha = 255;
}

void Firework::update(){
    vel += acc;
    pos += vel;
    
    alpha --;
}

void Firework::draw(float _r,float _g,float _b){
    
//    distance = ofDist(pos.x, pos.y, startingPos.x, startingPos.y);
//    offset = ofMap(distance, 0, 200, 0, 255);
    
    ofSetColor(_r, _g, _b ,alpha);
    ofDrawCircle(pos, size);
}

void Firework::restart(float _x, float _y){
    pos.x = ofGetWidth()/2 + _x;
    pos.y = 50 + _y;
    
//    startingPos.x = pos.x;
//    startingPos.y = pos.y;
    
    vel.x = ofRandom(-1,1);
    vel.y = ofRandom(-1,1);
    
    acc.y = ofRandom(0,0.01);
    
    alpha = 255;
}