//
//  FlowField.hpp
//  vectorPic
//
//  Created by Danli Hu on 11/3/16.
//
//

#pragma once
#include "ofMain.h"

class FlowField {
public:

    void setup( int width, int height, int res );
    void applyImg(float _brightness);
    void draw();
    
    void drawVector( const ofVec3f &start, const ofVec3f &end, float headLength = 0.2f, float headRadius = 0.05f );
    void drawVectorAt( const ofVec2f &vec, const ofVec2f &pos );
    
    vector< vector<ofVec2f> > flowList;
    int fieldWidth, fieldHeight, resolution;
};
