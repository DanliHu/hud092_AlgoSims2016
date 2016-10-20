//
//  Ripple.hpp
//  seek
//
//  Created by Danli Hu on 10/20/16.
//
//

#pragma once
#include "ofMain.h"

class Ripple{

public:
    void setup(float _x, float _y);
    void update(float _speed);
    void draw(float _speed);
    
    ofPoint pos;
    float radius;
};
