//
//  MyBall.hpp
//  BouncingBall
//
//  Created by Danli Hu on 9/8/16.
//
//

#pragma once

#include "ofMain.h"

class MyBall{
    
public:
    
    MyBall();
    
    void setup(float _x,float _y);
    void update();
    void draw();
    void split();
    
    ofPoint position;
    ofVec2f velocity;
    
    float alpha;
    float size;
};