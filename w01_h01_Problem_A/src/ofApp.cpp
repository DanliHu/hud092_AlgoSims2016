#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    for (int i=0; i<6; i++) {
        MyObj temp;
        obj.push_back(temp);
        
        float offsetY = 0.1 + ((float)i/5 * 0.8);
        
        obj[i].setSrc(ofGetWidth()*0.25, ofGetHeight()*offsetY);
        obj[i].setDst(ofGetWidth()*0.75, ofGetHeight()*offsetY);
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    pct += 0.01;
    
    if(pct>1.0){
        pct = 0;
    }
    
    for(int i=0; i<6; i++){
        obj[i].powUpdatePct(pct, (float)i/5);
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i=0; i<6; i++) {
        obj[i].draw();
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
