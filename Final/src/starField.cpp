//
//  starField.cpp
//  zooming3_webCam
//
//  Created by Danli Hu on 12/15/16.
//
//

#include "starField.hpp"

void StarField::setup(){
    
    num = 800;
    for(int i=0; i<num; i++){
        Star temp;
        temp.setup();
        stars.push_back(temp);
    }
}

void StarField::update(){
    for (int i=0; i<stars.size(); i++) {
        stars[i].update();
    }
}

void StarField::draw(){
    
    ofPushMatrix();
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    for (int i=0; i<stars.size(); i++) {
        stars[i].draw();
    }
    
    ofPopMatrix();
}