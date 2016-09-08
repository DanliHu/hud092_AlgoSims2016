//
//  MyCircle.hpp
//  w01_h01_Problem_C
//
//  Created by Danli Hu on 9/3/16.
//
//


#pragma once

#include "ofMain.h"

class MyCircle{

public:
    void setup();
    void update(float _shaper);
    void draw();
    
    float a, b, num, pct1, pct2, color, radius;
};