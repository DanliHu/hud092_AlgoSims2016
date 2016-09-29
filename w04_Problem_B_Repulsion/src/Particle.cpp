//
//  Particle.cpp
//  w04_Problem_B_Repulsion
//
//  Created by Danli Hu on 9/28/16.
//
//

#include "Particle.hpp"

Particle::Particle(){
    setInitial(ofPoint(0,0), ofPoint(0,0));
    damping = 0.09;
}

void Particle::setInitial(ofPoint _pos, ofPoint _vel){
    pos.set(_pos.x,_pos.y);
    vel.set(_vel.x,_vel.y);
}

void Particle::update(){
    vel = vel + force;
    pos = pos + vel;
}

void Particle::resetForce(){
    force.set(0,0);
}

void Particle::addDamping(){
    force = force - vel * damping;
}

void Particle::addRepulsionForce(ofPoint _pos, float _radius, float _strength){
    ofPoint posOfForce;
    posOfForce.set(_pos.x, _pos.y);
    
    ofPoint diff = pos - posOfForce;
    
    if(diff.length() < _radius){
        diff *= ofMap(diff.length(), 0, _radius, 1, 0);
        force += diff * _strength;
    }
}

void Particle::addAttractionForce(ofPoint _pos, float _radius, float _strength){
    ofPoint posOfForce;
    posOfForce.set(_pos.x, _pos.y);
    
    ofPoint diff = pos - posOfForce;
    
    if(diff.length() < _radius){
        diff *= ofMap(diff.length(), 0, _radius, 1, 0);
        force -= diff * _strength;
    }
}

void Particle::draw(){
    ofDrawCircle(pos, 2);
}