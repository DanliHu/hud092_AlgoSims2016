//
//  MyBall.cpp
//  BouncingBall
//
//  Created by Danli Hu on 9/8/16.
//
//

#include "MyBall.hpp"

//constructor

MyBall:: MyBall(){
    velocity.x = ofRandom(0,1);
    velocity.y = ofRandom(0,1);
//    alpha = 255;
    size = 30;
    
}

void MyBall::setup(float _x,float _y){
    position.x = _x;
    position.y = _y;
}

void MyBall::update(){
    position.x += velocity.x * 10;
    position.y += velocity.y * 10;
    
    if(position.x < size/2 || position.x > ofGetWidth()-size/2){
        velocity.x = velocity.x * -1;
    }
    if(position.y < size/2 || position.y > ofGetHeight()-size/2){
        velocity.y = velocity.y * -1;
    }
    
//    alpha--;
    
}

void MyBall::draw(){
//    ofSetColor(255, 0, 0, alpha);
    ofSetColor(255, 0, 0);
    ofDrawCircle(position, size);
}

//void MyBall::split(){
//    ofSetColor(255, 0, 0);
//    ofDrawCircle(position, size/2);
//    ofDrawCircle(position, size/2);
//}