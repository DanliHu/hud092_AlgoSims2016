//
//  star.cpp
//  zooming3_webCam
//
//  Created by Danli Hu on 12/15/16.
//
//

#include "star.hpp"

void Star::setup(){
    starX = ofRandom(-ofGetWidth()/2, ofGetWidth()/2);
    starY = ofRandom(-ofGetHeight()/2, ofGetHeight()/2);
    starZ = ofRandom(ofGetWidth()/2);
    
    pz = starZ;
}

void Star::update(){
    speed = 50;
    starZ -= speed;
    
    if (starZ < 1) {
        starZ = ofGetWidth()/2;
        starX = ofRandom(-ofGetWidth()/2, ofGetWidth()/2);
        starY = ofRandom(-ofGetHeight()/2, ofGetHeight()/2);
        pz = starZ;
    }
}

void Star::draw(){

    float sx = ofMap(starX / starZ, 0, 1, 0, ofGetWidth()/2);
    float sy = ofMap(starY / starZ, 0, 1, 0, ofGetHeight()/2);
    
    float r = ofMap(starZ, 0, ofGetWidth()/2, 16, 0);
    
    float px = ofMap(starX / pz, 0, 1, 0, ofGetWidth()/2);
    float py = ofMap(starY / pz, 0, 1, 0, ofGetHeight()/2);
    
    pz = starZ;
    
    ofDrawLine(px, py, sx, sy);
}