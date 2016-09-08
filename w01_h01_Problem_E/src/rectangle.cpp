//
//  rectangle.cpp
//  rectangleXeno
//
//  Created by Regina Flores on 9/1/16.
//
//

#include "rectangle.hpp"


rectangle:: rectangle() {
    catchUpSpeed = 0.1;
    
}

void rectangle::draw(float _size, float _color){
    
    ofFill();
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    ofSetColor(_color, 150, 100);
    
    ofDrawCircle(pos.x, pos.y, _size, _size);
}

void rectangle::xenoToPoint(float catchX, float catchY){
    //Xeno formula:
    //myPos = (1-pct) * myPos + pct * targetPos
    
    pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) *pos.x;
    pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) *pos.y;
    
}