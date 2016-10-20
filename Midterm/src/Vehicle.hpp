//
//  Vehicle.hpp
//  seek
//
//  Created by Danli Hu on 10/19/16.
//
//

#pragma once
#include "ofMain.h"

class Vehicle {
    
public:
    Vehicle();
    void update(vector<Vehicle> *vehicles);
    void applyForce(ofPoint _force);
    void seek(ofPoint _target);
    void arrive(ofPoint _target);
    void display();
    
    ofPoint separation(vector<Vehicle> * vehicles);
    void addRepulsionForce(ofPoint _pos);
    
    void resetForce();
    
    ofPoint loc, vel, acc, force;
    float r, maxforce, maxspeed, edge = 20;
    float length = 10, size = 2;
    
    int count = 0;

};