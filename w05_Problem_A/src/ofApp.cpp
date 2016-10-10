#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(255);
    k = 0.05;
    restLength = 200;
    
    anchor = ofVec2f(0, 10);
    ball = ofVec2f(0, restLength + 50);

}

//--------------------------------------------------------------

void ofApp::applyForce(ofVec2f force){
acc.x += force.x;
acc.y += force.y;
}

//--------------------------------------------------------------

void ofApp::update(){
    
    ofVec2f force = ball - anchor;
    float currentLength = force.length();
    float x = currentLength - restLength;
    force.normalize();
    force *= -1 * k * x;
    applyForce(force);
    applyForce(ofVec2f(0,1.0));
    
    vel+=acc;
    vel*=0.98;
    ball+=vel;
    acc*=0;

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofTranslate(ofGetWidth()/2,0);
    
    ofSetColor(0);
    
    for (int count=0; count<ball.y; count++) {
        y = count;
        angle = ofDegToRad(count);
        float length = angle*numOfWaves;
        x = sin(length);
        x = ofMap(x, -1, 1, -10, 10);
        ofDrawCircle(x,y+anchor.y,1);
    }
    
    ofDrawCircle(anchor, 10);
    ofDrawCircle(ball, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
