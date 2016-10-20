//
//  Ripple.cpp
//  seek
//
//  Created by Danli Hu on 10/20/16.
//
//

#include "Ripple.hpp"

void Ripple::setup(float _x, float _y){
    pos.x = _x;
    pos.y = _y;
    radius = 0;
}

void Ripple::update(float _speed){
    float maxSize = ofMap(_speed, 0, 200, 0, 200);
    if (radius  <  maxSize) {
        radius++;
    }
}

void Ripple::draw(float _speed){
    float maxSize = ofMap(_speed, 0, 200, 0, 200);
    radius = maxSize;
    
    ofNoFill();
    ofDrawCircle(pos, radius);
}