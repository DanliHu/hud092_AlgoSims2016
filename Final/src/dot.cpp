//
//  dot.cpp
//  tunnel2test
//
//  Created by Danli Hu on 12/15/16.
//
//

#include "dot.hpp"

void Dots::setup(ofPoint _pos){
//    pos1 = ofPoint(ofGetWidth()/2,ofGetHeight()/2);
//    pos2 = ofPoint(ofGetWidth()/2,ofGetHeight()/2);
//    pos3 = ofPoint(ofGetWidth()/2,ofGetHeight()/2);
    
    pos1 = _pos;
    pos2 = _pos;
    pos3 = _pos;
    
    radius = 10;
    size = 1;
}

void Dots::update(float _offset){
    float time = _offset;
    
    pos1.x = pos1.x + sin(time)*radius+2;
    pos1.y = pos1.y + cos(time)*radius+2;

    pos2.x = pos2.x + sin(time)*(radius+2);
    pos2.y = pos2.y + cos(time)*(radius+2);
    
    pos3.x = pos3.x + sin(time)*radius-2;
    pos3.y = pos3.y + cos(time)*radius+2;
    
    radius+=0.2;
    size += 0.2;
}

void Dots::draw(){
    
//    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    ofDrawEllipse(pos1,size,size);
    ofDrawEllipse(pos2,size,size);
    ofDrawEllipse(pos3,size,size);
    
    ofDrawLine(pos1,pos2);
    ofDrawLine(pos2, pos3);
    
}