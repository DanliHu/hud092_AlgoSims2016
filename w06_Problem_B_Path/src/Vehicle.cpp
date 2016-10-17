//
//  Vehicle.cpp
//  w06_Problem_B_Path
//
//  Created by Danli Hu on 10/17/16.
//
//

#include "Vehicle.hpp"

void Vehicle::setup(float _x, float _y){
    pos = ofVec2f(_x, _y);
    vel = ofVec2f(0,0);
    acc = ofVec2f(0,0);
    r = 3;
    maxspeed = 4;
    maxforce = 0.1;
}

void Vehicle::update(){
    vel = vel + acc;
    vel = vel.limit(maxspeed);
    pos = pos + vel;
    acc = acc * 0;
}

ofVec2f Vehicle::follow(Path _p){
    ofVec2f predict = vel;
    predict = predict.normalize();
    predict = predict * 25;
    ofVec2f predictLoc = pos + predict;
    
    ofVec2f a = predictLoc - _p.start;
    b = _p.end - _p.start;
    b = b.normalize();
    b = b * (a.dot(b));
    
    ofVec2f target = normalPoint + b;
    
    normalPoint = _p.start + b;
    float distance = ofDist(predictLoc.x,predictLoc.y,normalPoint.x,normalPoint.y);
    
    if (distance > _p.radius) {
        seek(target);
    }
    
    return target;
}


void Vehicle::draw(){
    
    ofPushMatrix();
    ofTranslate( pos );
    
    float rotAmt = atan2( vel.y, vel.x );
    ofRotate( ofRadToDeg(rotAmt) + 90 );
    ofDrawTriangle(0, -r*3, -r, r*3, r, r*3);
    ofPopMatrix();
    
    if(pos.x > ofGetWidth()){
        pos.x = 0;
    }
}

ofVec2f Vehicle::seek(ofVec2f _target){
    ofVec2f desired = _target - pos;
    desired = desired.normalize();
    desired = desired * maxspeed;
    ofVec2f steer = desired - vel;
    steer.limit(maxspeed);
    
    return steer;
}

void Vehicle::applyforce(ofVec2f _force){
    acc = acc + _force;
}