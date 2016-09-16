//
//  Wave.hpp
//  w02_h01_Problem_B
//
//  Created by Danli Hu on 9/15/16.
//
//

#pragma once

#include "ofMain.h"

class Wave{
public:
    
    void setup(float _posY);
    void update();
    void draw(float _color);
    
    float posX=0, posY, y, count=0;
};
