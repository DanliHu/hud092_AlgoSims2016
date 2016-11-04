//
//  Individual.hpp
//  noiseTest
//
//  Created by Danli Hu on 11/3/16.
//
//

#pragma once
#include "ofMain.h"

class Individual{

public:
    
    void setup(ofPoint _pos);
    void update(float _w);
    void draw(ofColor _color);
    
    ofPoint pos;
    float w, h;
};
