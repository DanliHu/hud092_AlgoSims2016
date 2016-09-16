//
//  Wave.cpp
//  w02_h01_Problem_B
//
//  Created by Danli Hu on 9/15/16.
//
//

#include "Wave.hpp"

void Wave::setup(float _posY){
    posY = _posY;
}

void Wave::update(){
    y = sin(count)*10;
    count += ofRandom(0.05,0.5);
    posY += y;
    
    posX ++;
    
    if(posX > ofGetWidth()){
        posX = 0;
    }
    
    cout<<posX<<endl ;
}

void Wave::draw(float _color){
    ofSetColor(0, 0, _color);
    ofDrawCircle(posX,posY,1);
}