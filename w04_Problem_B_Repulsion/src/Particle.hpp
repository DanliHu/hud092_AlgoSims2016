//
//  Particle.hpp
//  w04_Problem_B_Repulsion
//
//  Created by Danli Hu on 9/28/16.
//
//

#pragma once
#include "ofMain.h"

class Particle{
public:
    
    Particle();
    void resetForce();
    void addDamping();
    void setInitial(ofPoint _pos, ofPoint _vel);
    void update();
    void draw();
    void addRepulsionForce(ofPoint _pos, float _radius, float _strength);
    void addAttractionForce(ofPoint _pos, float _radius, float _strength);
private:
    ofPoint pos, vel, force;
    float damping;
};
