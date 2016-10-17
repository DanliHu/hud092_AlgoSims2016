#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    num = 1000;
    
    for (int i=0; i<num; i++) {
        Particle temp;
        flocking.push_back(temp);
        flocking[i].init();
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i=0; i<num; i++) {
        flocking[i].update(flocking);
        flocking[i].bounding();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.begin();
    
    for (int i=0; i<num; i++) {
        flocking[i].draw();
    }
    
    cam.end();

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
