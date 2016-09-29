#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    img.loadImage("Phoenix2.jpg");
    
    for (int x=0; x<ofGetWidth(); x++) {
        for (int y=0; y<ofGetHeight(); y++) {
            
            ofColor temp;
            temp = ofColor(img.getColor(x, y));
            color.push_back(temp);
            
            Particle tempP;
            tempP.setup(x, y);
            particles.push_back(tempP);
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int x=0; x<ofGetWidth(); x++) {
        for (int y=0; y<ofGetHeight(); y++) {
            
            loc = x + y * ofGetWidth();
        
            if(color[loc].getBrightness() > thereshold){
            particles[loc].draw(color[loc]);
            }
        }
    }
    
//    img.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    for (int x=0; x<ofGetWidth(); x++) {
        for (int y=0; y<ofGetHeight(); y++) {
            
            loc = x + y * ofGetWidth();
            
            particles[loc].update();
        }
    }
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
