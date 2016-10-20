//
//  Particle.hpp
//  w04_Problem_C
//
//  Created by Danli Hu on 9/29/16.
//
//

#pragma once
#include "ofMain.h"

class Particle{
public:
    
    Particle();
    
    void setup(float _x, float _y, float _imgWidth, float _imgHeight);
    void update();
    
    void draw(ofColor _color);
    void restart(float _x, float _y);
    
    ofPoint pos, vel;
    ofColor color;
    
    float alpha, damping;
};