#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0,0,0);
    ofSetBackgroundAuto(false);
    pos.x = ofGetWidth()/2;
    pos.y = ofGetHeight()/2;
    color.r = 255;
    color.g = 0;
    color.b = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    distance = ofDist(ofGetWidth()/2, ofGetHeight()/2, pos.x, pos.y);
    length = ofMap(distance, 0, 384, 100, 20);
    size = ofMap(distance, 0, 384, 10, 2);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(color);
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    ofRotate(ofGetFrameNum()*10, 0, 0, 1);
    ofDrawLine(length*-1, 0, length, 0);
    ofDrawCircle(length*-1,0, size);
    ofDrawCircle(length,0, size);
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key) {
        ofBackground(0,0,0);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    pos.x = x;
    pos.y = y;

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
