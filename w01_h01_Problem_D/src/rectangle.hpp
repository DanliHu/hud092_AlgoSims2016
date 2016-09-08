//
//  rectangle.hpp
//  w01_h01_Problem_D
//
//  Created by Danli Hu on 9/7/16.
//
//

#pragma once
#include "ofMain.h"

class Rectangle{
    
public:
    //constructor
    Rectangle();
    
    void draw(float _color);
    void xenoToPoint(float catchX, float catchY);
    
    ofPoint pos;
    
    float catchUpSpeed;
};
