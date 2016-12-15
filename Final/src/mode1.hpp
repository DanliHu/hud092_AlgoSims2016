//
//  mode1.hpp
//  zooming3_webCam
//
//  Created by Danli Hu on 12/15/16.
//
//

#pragma once
#include "ofMain.h"
#include "rectangle.hpp"

class mode1{
    
public:
    
    void setup();
    void update();
    void draw(bool _autoMode, bool _motionMode, float _xOff);
    
    float xoff, yoff;
    
    vector<Rectangle> myRects;

};
