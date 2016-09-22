//
//  Firework.hpp
//  w03_Problem_A_Fireworks
//
//  Created by Danli Hu on 9/21/16.
//
//

#pragma once
#include "ofmain.h"


class Firework {
public:
    void start();
    void update();
    void draw(float _r,float _g,float _b);
    void restart(float _x, float _y);
    
    ofPoint pos, startingPos, vel, acc;
    float size = 1.3, radius, x,y, alpha, distance, offset;

};