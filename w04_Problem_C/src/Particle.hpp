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
    
    void setup(float _x, float _y);
    void update(Particle *_particles);
    
    void draw(Particle *_particles, ofColor *_color);
    void restart(float _x, float _y);
    
    ofPoint *pos, *vel, *originPos;
    ofColor color;
    
    float alpha, damping;
};