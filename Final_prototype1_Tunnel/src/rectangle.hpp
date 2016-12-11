//
//  rectangle.hpp
//  zooming1
//
//  Created by Danli Hu on 11/28/16.
//
//

#pragma once
#include "ofMain.h"

class Rectangle{
public:
    void setup(ofPoint _pos, float _size);
    void update();
    void draw();
    void reset();
    
    ofPoint topLeft();
    ofPoint topRight();
    ofPoint bottomLeft();
    ofPoint bottomRight();
    
    ofPoint pos;
    float size;
    float acc;
};