//
//  Particle.cpp
//  w04_Problem_A_Orbit
//
//  Created by Danli Hu on 9/28/16.
//
//

#include "Particle.hpp"

void Particle::set(float _dist, float _intAngle){
    radius = _dist;
    angle = _intAngle;
    shrink = 0.1;
}

void Particle::update(float _step, ofPoint _center){
    float distance = ofDist(x, y, _center.x, _center.y);
    float offset = ofMap(distance, 0, ofGetWidth()/2, 0.1, 3);
    
    _step = _step * offset;
    
    angle += _step;
    x = _center.x + radius * cos(angle);
    y = _center.y + radius * sin(angle);
    
    radius -= shrink;
}

void Particle::draw(ofColor _color){
    ofSetColor(_color);
    ofDrawCircle(*this,1);
}

void Particle::restart(float _size){
    radius = _size;
}