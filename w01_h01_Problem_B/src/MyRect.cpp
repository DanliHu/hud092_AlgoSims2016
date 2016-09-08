//
//  MyRect.cpp
//  w01_h01_Problem_B
//
//  Created by Danli Hu on 9/2/16.
//
//

#include "MyRect.hpp"

void MyRect::setPos(float _x, float _y){
    pos.set(_x, _y);
}

void MyRect::updatePos(float _x, float _y){
    pos.set(_x, _y);
}

void MyRect::draw(float _r,float _g,float _b){
    ofSetColor(_r, _g, _b);
    ofFill();
    ofRect(pos, 100, 100);
}