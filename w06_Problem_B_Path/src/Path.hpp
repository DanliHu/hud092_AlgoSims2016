//
//  Path.hpp
//  w06_Problem_B_Path
//
//  Created by Danli Hu on 10/17/16.
//
//

#pragma once
#include "ofMain.h"

class Path{
public:
    Path();
    void display();
    
    ofPoint start, end;
    float radius;
};