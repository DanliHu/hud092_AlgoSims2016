//
//  MyCircle.cpp
//  w01_h01_Problem_C
//
//  Created by Danli Hu on 9/3/16.
//
//

#include "MyCircle.hpp"

void MyCircle::setup(){
    ofSetCircleResolution(100);
    a=10;
    b=20;
    num=0;
}

void MyCircle::update(float _shaper){
    ////pct = powf(num,shaper); myPoss = (1-pct) * a + pct * b;
    num += 0.01;
    if(num>1.0){
        num=0;
    }
    
    pct1 = powf(num, _shaper);
    pct2 = powf(num, _shaper);
    
    color = (1-pct1) * a + pct1 * b;
    radius = (1-pct2) * a + pct2 * b;
}

void MyCircle::draw(){
    ofSetColor(color*5,100,100);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, radius*10);
}
