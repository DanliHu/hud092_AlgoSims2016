//
//  Particle.cpp
//  w04_Problem_C
//
//  Created by Danli Hu on 9/29/16.
//
//

#include "Particle.hpp"


Particle::Particle(){
    acc.set(0,0);
    vel.set(0,0);
    setup(0,0,0,0);
    damping = 1.01;
    
    maxspeed = 4;
    maxforce = 0.1;
}

ofPoint Particle::setup(float _x, float _y, float _imgWidth, float _imgHeight){
    
    pos.x = _x + (ofGetWidth()/2 - _imgWidth/2);
    pos.y = _y + (ofGetHeight()/2 - _imgHeight/2);
    
    originPos.x = _x + (ofGetWidth()/2 - _imgWidth/2);
    originPos.y = _y + (ofGetHeight()/2 - _imgHeight/2);
    
    return originPos;
}

void Particle::falling(){
    vel.x = ofRandom(-3,3);
    vel.y = ofRandom(1,10);
}

void Particle::pile(){
    
    //    PILE UP AT THE BOTTOM
    float randomNum = ofGetHeight() - 30 + ofRandom(10);
    if(pos.y > randomNum){
        pos.y = randomNum;
    }
}


void Particle::update(){
//    vel *= damping;
    vel += acc;
    pos += vel;
}

void Particle::updateAttraction(vector<Particle> &particles){
    vel += acc;
    vel += separation(particles);
    vel.limit(maxspeed);
    pos += vel;
    acc.set(0, 0);
}

void Particle::applyForce(ofPoint _force){
    acc += _force;
}

void Particle::seek(ofPoint _target){
    ofPoint desired = _target - pos;
    desired.normalize();
    desired *= maxspeed;
    ofPoint steer = desired - vel;
    steer.limit(maxforce);
    applyForce(steer);
}

void Particle::arrive(ofPoint _target){
    ofPoint desired = _target - pos;
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

ofPoint Particle::separation(vector<Particle> &particles) {
    ofPoint separationVel;
    
    for (int i=0; i<particles.size(); i++) {
        
        for (int i=0; i<particles.size(); i++) {
            if(&particles[i] == this){
                continue;
            }
            
            float dist = ofDist(particles[i].pos.x, particles[i].pos.y, pos.x, pos.y);
            if(dist < 100){
                separationVel = separationVel - (particles[i].pos - pos);
            }
        }
    }
    return separationVel;
}

void Particle::draw(ofColor color){
    ofSetColor(color);
    ofDrawCircle(pos, 1);
}


