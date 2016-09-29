//
//  Particle.hpp
//  w04_Problem_A_Orbit
//
//  Created by Danli Hu on 9/28/16.
//
//

#pragma once
#include "ofMain.h"

class Particle: public ofPoint{
public:
    void set(float _dist, float _intAngle);
    void update(float _step, ofPoint _center);
    void draw(ofColor _color);
    void restart(float _size);
    
    float radius, angle, shrink;
};
