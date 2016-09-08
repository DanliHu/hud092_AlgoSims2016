//
//  MyRect.hpp
//  w01_h01_Problem_B
//
//  Created by Danli Hu on 9/2/16.
//
//
#pragma once

#include "ofMain.h"

class MyRect {

public:
    void setPos(float _x, float _y);
    void updatePos(float _x, float _y);
    void draw(float _r, float _g, float _b);
    
    ofPoint pos;
    
private:

};
