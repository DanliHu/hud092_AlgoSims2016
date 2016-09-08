#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetCircleResolution(100);
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();

    for (int i=0; i<10; i++) {
        rectangle temp;
        myRect.push_back(temp);
        
        myRect[i].pos.x = ofGetWidth()/2;
        myRect[i].pos.y = ofGetHeight()/2;
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    prePos.x=mouseX;
    prePos.y=mouseY;
    
    for (int i=0; i<10; i++) {
        myRect[i].xenoToPoint(prePos.x, prePos.y);
        prePos.x=myRect[i].pos.x;
        prePos.y=myRect[i].pos.y;
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i=0; i<10; i++) {
    myRect[i].draw(50-i*4,i*30);
    }
    
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
