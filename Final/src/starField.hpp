//
//  starField.hpp
//  zooming3_webCam
//
//  Created by Danli Hu on 12/15/16.
//
//

#pragma once
#include "ofMain.h"
#include "star.hpp"

class StarField{
public:
    void setup();
    void update();
    void draw();
};

vector<Star> stars;
int num;
