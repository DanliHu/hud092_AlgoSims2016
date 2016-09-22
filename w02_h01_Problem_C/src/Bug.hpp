//
//  Bug.hpp
//  w02_h01_Problem_C
//
//  Created by Danli Hu on 9/15/16.
//
//

#pragma once

#include "ofMain.h"

class Bug{

public:
    
    void setup();
    void update();
    void draw();
    void follow();
    
    ofPoint pos;
    float w=100, h=50, length=100, count=0;
};
