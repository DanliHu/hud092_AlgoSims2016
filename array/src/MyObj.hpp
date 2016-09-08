//
//  MyObj.hpp
//  w01_h01_Problem_A
//
//  Created by Danli Hu on 9/1/16.
//
//

#pragma once //just do this

#include "ofMain.h"

class MyObj {
    
public:
    void setSrc(float _x, float _y);
    void setDst(float _x, float _y);
    
    void updatePct(float _pct);
    void powUpdatePct(float _pct,float _shaper);
    
    void draw();
    
private:
    ofPoint src, dst; //vector
    ofPoint pos;
    
};