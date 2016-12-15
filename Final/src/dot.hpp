//
//  dot.hpp
//  tunnel2test
//
//  Created by Danli Hu on 12/15/16.
//
//

#pragma once
#include "ofMain.h"

class Dots{
public:
    void setup(ofPoint _pos);
    void update(float _offset);
    void draw();
    
    ofPoint pos1, pos2, pos3;
    float radius;
    float size;
};
