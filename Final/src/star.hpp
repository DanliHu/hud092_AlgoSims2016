//
//  star.hpp
//  zooming3_webCam
//
//  Created by Danli Hu on 12/15/16.
//
//

#pragma once
#include "ofMain.h"

class Star{
    
public:
    void setup();
    void update();
    void draw();
    
    float starX, starY, starZ;
    
    float pz;
    float speed;
};

