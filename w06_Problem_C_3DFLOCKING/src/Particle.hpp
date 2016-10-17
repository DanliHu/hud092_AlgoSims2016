//
//  Particle.hpp
//  w06_Problem_C_3DFLOCKING
//
//  Created by Danli Hu on 10/15/16.
//
//

#pragma once
#include "ofMain.h"

class Particle{

public:
    Particle();
    
    void init();
    void bounding();
    void draw();
    void update(vector<Particle> &particles);
    
    ofPoint cohesion(vector<Particle> &particles);
    ofPoint separation(vector<Particle> &particles);
    ofPoint alignment(vector<Particle> &particles);
    
    ofPoint pos, vel;
    int radius, size = 300;
    float alpha;
};
