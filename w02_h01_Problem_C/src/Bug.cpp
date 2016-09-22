//
//  Bug.cpp
//  w02_h01_Problem_C
//
//  Created by Danli Hu on 9/15/16.
//
//

#include "Bug.hpp"

void Bug::setup(){
    pos.x = ofGetWidth()/2;
    pos.y = ofGetHeight()/2;
}

void Bug::update(){

    count += 0.1;
}

void Bug::draw(){
    ofSetColor(100, 100, 100);
//    ofDrawEllipse(pos,w,h);
    
    }
}

void Bug::follow(){
}

