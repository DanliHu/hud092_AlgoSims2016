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
    ofPoint setup(float _x, float _y, float _imgWidth, float _imgHeight);
    
    //stage one
    void falling();
    void pile();
    void update();
    
    //stage two
    void updateAttraction(vector<Particle> &particles);
    void applyForce(ofPoint _force);
    void seek(ofPoint _target);
    void arrive(ofPoint _target);
    
    ofPoint separation(vector<Particle> &particles);
    
    //display
    void draw(ofColor color);
    
    ofPoint pos, vel, acc, originPos;
    ofColor color;
    
    float alpha, damping;
    float r, maxforce, maxspeed, edge = 20;
    
    int count = 0;
    
    bool mouseFollow = false;
};