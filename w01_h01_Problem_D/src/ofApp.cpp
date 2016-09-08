#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    
    for (int i=0; i<5; i++) {
        Rectangle temp;
        rect.push_back(temp);
        
        rect[i].pos.x = ofRandom(ofGetWidth());
        rect[i].pos.y = ofRandom(ofGetHeight());
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i=0; i<5; i++) {
        rect[i].xenoToPoint(mouseX, mouseY);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i=0; i<5; i++) {
        rect[i].draw(i * 50 + 10);
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
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