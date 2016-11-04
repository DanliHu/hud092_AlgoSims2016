//
//  Individual.cpp
//  noiseTest
//
//  Created by Danli Hu on 11/3/16.
//
//

#include "Individual.hpp"

void Individual::setup(ofPoint _pos){
    pos.x = _pos.x;
    pos.y = _pos.y;
    w = 1;
}

void Individual::update(float _w){
//    w = ofNoise(ofGetElapsedTimef())*10;
    w = _w;
}

void Individual::draw(ofColor _color){
    ofSetColor(_color);
    ofDrawRectangle(pos, w, w);
}