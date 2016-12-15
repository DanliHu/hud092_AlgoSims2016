//
//  mode2.hpp
//  zooming3_webCam
//
//  Created by Danli Hu on 12/15/16.
//
//

#pragma once
#include "ofMain.h"
#include "dot.hpp"

class mode2{
public:
    void update();
    void draw(bool _autoMode, bool _motionMode, float _xOff);
    
    vector<Dots> myDots;
    vector<Dots> myDots2;
    vector<Dots> myDots3;
    
};