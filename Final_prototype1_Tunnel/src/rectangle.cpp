//
//  rectangle.cpp
//  zooming1
//
//  Created by Danli Hu on 11/28/16.
//
//

#include "rectangle.hpp"

void Rectangle::setup(ofPoint _pos, float _size){
    
//    pos = ofPoint(0,0);
//    size = 2;
    
    pos = _pos;
    size = _size;
}

void Rectangle::update(){
    acc = 1.05;
    size *= acc;
   
//    if (size > ofGetWidth()) {
//        size = 2;
//    }
}

void Rectangle::draw(){
//    ofSetColor(255);
    ofDrawRectangle(pos,size,size);
    
    ofDrawCircle(topLeft().x,topLeft().y,size/100+0.5);
    ofDrawCircle(topRight().x,topRight().y,size/100+0.5);
    ofDrawCircle(bottomLeft().x,bottomLeft().y,size/100+0.5);
    ofDrawCircle(bottomRight().x,bottomRight().y,size/100+0.5);
}

ofPoint Rectangle::topLeft(){
    ofPoint topLeft = ofPoint((pos.x-size/2),(pos.y-size/2));
    return topLeft;
}

ofPoint Rectangle::topRight(){
    ofPoint topRight = ofPoint((pos.x+size/2),(pos.y-size/2));
    return topRight;
}

ofPoint Rectangle::bottomLeft(){
    ofPoint bottomLeft = ofPoint((pos.x-size/2),(pos.y+size/2));
    return bottomLeft;
}

ofPoint Rectangle::bottomRight(){
    ofPoint bottomRight = ofPoint((pos.x+size/2),(pos.y+size/2));
    return bottomRight;
}
