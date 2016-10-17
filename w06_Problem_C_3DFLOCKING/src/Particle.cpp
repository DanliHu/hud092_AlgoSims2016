//
//  Particle.cpp
//  w06_Problem_C_3DFLOCKING
//
//  Created by Danli Hu on 10/15/16.
//
//

#include "Particle.hpp"

Particle::Particle(){
    radius = 2;
}

void Particle::init(){
//    pos = ofPoint(ofRandom(-size/2, size/2),ofRandom(-size/2,size/2),ofRandom(-size/2,size/2));
    pos = ofPoint(0,0,0);
    vel = ofPoint(ofRandom(-1,1),ofRandom(-1,1),ofRandom(-1,1));
//    vel = ofPoint(ofRandom(-1,1),ofRandom(-1,1),0);
}

void Particle::bounding(){

//    if (pos.y>ofGetHeight()/2 || pos.y< -ofGetHeight()/2) {
//        vel = -vel;
//    }
//    if (pos.x>ofGetWidth()/2 || pos.x< -ofGetWidth()/2) {
//        vel = -vel;
//    }
    
    float distance = ofDist(pos.x, pos.y, pos.z, 0, 0, 0);
    if (distance >= size) {
        vel = -vel;
    }
    
//    if(pos.y > 200 || pos.y < -200){
//        vel.y = -vel.y;
//    }
//    
//    if(pos.x > 200 || pos.x < -200){
//        vel.x = -vel.x;
//    }
//    
//    if(pos.z > 200 || pos.z < -200){
//        vel.z = -vel.z;
//    }
}

void Particle::draw(){
    
    alpha = ofMap(pos.z, size, -size, 255, 0);
    ofSetColor(255,alpha);
    ofPushMatrix();
    float rotAmt = atan2(vel.x, vel.y);
    ofRotate(ofRadToDeg(rotAmt) + 90 );
    ofDrawEllipse(pos.x, pos.y, pos.z, radius, 2*radius);
    
    ofPopMatrix();
//    ofDrawCircle(pos.x, pos.y, pos.z, radius);
}

ofPoint Particle::cohesion(vector<Particle> &particles){
    ofPoint centerMass;
    for (int i=0; i<particles.size(); i++) {
        if (&particles[i] == this) {
            continue;
        }
        centerMass += particles[i].pos;
    }
    centerMass = centerMass/(particles.size()-1);
    ofPoint cohensionVel;
    cohensionVel = (centerMass-pos)/100.0f;
    return cohensionVel;
}

ofPoint Particle::separation(vector<Particle> &particles){
    ofPoint displace;
    for (int i=0; i<particles.size(); i++) {
        if (&particles[i] == this) {
            continue;
        }
//        float dist = pow(particles[i].pos.x - pos.x, 2)+pow(particles[i].pos.y-pos.y, 2);
        float dist = ofDist(particles[i].pos.x, particles[i].pos.y, particles[i].pos.z, pos.x, pos.y, pos.z);
//        dist = sqrt(dist);
        
        if (dist < 10) {
            displace = displace - (particles[i].pos - pos);
        }
    }
    ofPoint separationVel = displace;
    return separationVel;
}

ofPoint Particle::alignment(vector<Particle> &particles){
    ofPoint avgVel;
    for (int i=0; i<particles.size(); i++) {
        if (&particles[i] == this) {
            continue;
        }
        avgVel += particles[i].vel;
    }
    avgVel = avgVel/(particles.size()-1);
    ofPoint alignmentVel = (avgVel - vel)/8.0f;
    return alignmentVel;
}

void Particle::update(vector<Particle> &particles){
    vel += cohesion(particles) + separation(particles) + alignment(particles);
    pos = pos + vel;
}



