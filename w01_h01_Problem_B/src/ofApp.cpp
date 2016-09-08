#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetRectMode(OF_RECTMODE_CENTER);
    isRed = true;
    
    ofBackground(255, 255, 255);
    
    rec1.setPos(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
    rec2.setPos(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    rec1.draw(200, 100, 0);
    rec2.draw(0, 100, 200);

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
    if(isRed){
        rec1.updatePos(x, y);
        isRed = !isRed;
    }else{
        rec2.updatePos(x, y);
        isRed = !isRed;
    }
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
