//
//  Vehicle.cpp
//  seek
//
//  Created by Danli Hu on 10/19/16.
//
//

#include "Vehicle.hpp"

Vehicle::Vehicle(){
    acc.set(0, 0);
    vel.set(0, 0);
    loc = ofPoint(ofRandom(edge,ofGetWidth()-edge),ofRandom(edge,ofGetHeight()-edge));
    r = 1;
    maxspeed = 4;
    maxforce = 0.1;
}

void Vehicle::update(vector<Vehicle> *vehicles){
    vel += acc;
    vel += separation(vehicles);
    vel.limit(maxspeed);
    loc += vel;
    acc.set(0, 0);
    
    count ++;
    
//    for (int i=0; i<patterns.size(); i++) {
//        patterns[i].update();
//    }
}

void Vehicle::applyForce(ofPoint _force){
    acc += _force;
}

void Vehicle::resetForce(){
    force.set(0,0);
}

void Vehicle::seek(ofPoint _target){
    ofPoint desired = _target - loc;
    desired.normalize();
    desired *= maxspeed; //?
    ofPoint steer = desired - vel;
    steer.limit(maxforce);
    applyForce(steer);
}

void Vehicle::arrive(ofPoint _target){
    ofPoint desired = _target - loc;
    float distance = desired.length();
    desired.normalize();
    
    if (distance < 100) {
        float m = ofMap(distance,0,100,0,maxspeed);
        desired *= m;
    }else{
        desired *= maxspeed;
    }
    ofPoint steer = desired - vel;
    steer.limit(maxforce);
    applyForce(steer);
}

void Vehicle::display(){

//    ofPushMatrix();
//    ofTranslate(loc.x, loc.y);
//    ofRotate(ofGetFrameNum()*10, 0, 0, 1);
//    ofDrawLine(length*-1, 0, length, 0);
//    ofDrawCircle(length*-1,0, size);
//    ofDrawCircle(length,0, size);
//    ofPopMatrix();
     ofDrawCircle(loc, r);
}

void Vehicle::addRepulsionForce(ofPoint _pos){
    ofPoint posOfForce;
    posOfForce.set(_pos.x, _pos.y);
    
    ofPoint diff = loc - posOfForce;
    
    if(diff.length() < 50){
        diff *= ofMap(diff.length(), 0, 100, 1, 0);
        force += diff * 0.02;
        applyForce(force);
    }
}

ofPoint Vehicle::separation(vector<Vehicle> *vehicles) {
    ofPoint separationVel;
    
    for (int i=0; i<vehicles->size(); i++) {
        
        for (int i=0; i<vehicles->size(); i++) {
            if(&(*vehicles)[i] == this){
                continue;
            }
            
            float dist = ofDist((*vehicles)[i].loc.x, (*vehicles)[i].loc.y, loc.x, loc.y);
            if(dist < 2){
                separationVel = separationVel - ((*vehicles)[i].loc - loc);
            }
        }
    }
    return separationVel;
}