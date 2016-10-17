//
//  Vehicle.hpp
//  w06_Problem_B_Path
//
//  Created by Danli Hu on 10/17/16.
//
//

#pragma once
#include "ofMain.h"
#include "Path.hpp"

class Vehicle{
public:
    void setup(float _x, float _y);
    void update();
    void draw();
    ofVec2f seek(ofVec2f _target);
    
    ofVec2f follow(Path _p);
    void applyforce(ofVec2f _force);
    
    ofPoint pos, vel, acc;
    ofPoint normalPoint, b;
    
    float maxspeed, maxforce;
    float r;
};
