//
//  rectangle.hpp
//  rectangleXeno
//
//  Created by Regina Flores on 9/1/16.
//
//

#pragma once

#include "ofMain.h"


class rectangle {
    
public:
    
    rectangle();
    void draw(float _size, float _color);
    
    void xenoToPoint(float catchX, float catchY);
    
    ofPoint pos;
    
    float catchUpSpeed;
    
    
};