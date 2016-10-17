//
//  Path.cpp
//  w06_Problem_B_Path
//
//  Created by Danli Hu on 10/17/16.
//
//

#include "Path.hpp"

Path::Path(){
    radius = 20;
    start = ofPoint(0,ofGetHeight());
    end = ofPoint(ofGetWidth(),0);
}

void Path::display(){
    ofSetColor(0);
    ofDrawLine(start.x, start.y, end.x, end.y);
}