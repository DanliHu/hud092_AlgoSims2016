#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofSetBackgroundAuto(false);
    ofSetFrameRate(60);
    
    colorR = 100;
    colorG = 100;
    colorB = 255;
    
    for (int i=0; i<num; i++) {
        Firework temp;
        temp.start();
        fireworks.push_back(temp);
        colors.push_back(ofColor(ofRandom(0, 50),ofRandom(0, 50),ofRandom(0, 50)));
}
    
}

//--------------------------------------------------------------
void ofApp::update(){
    x = ofRandom(-100, 100);
    y = ofRandom(50,200);
    
    for (int i=0; i<num; i++) {
            if (fireworks[i].alpha == 0) {
                fireworks[i].restart(x, y);
                colorR = ofRandom(50,255);
                colorG = ofRandom(50,200);
                colorB = ofRandom(100,255);
        }
    }
   colorG --;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 0, 0, 18);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    for (int i=0; i<num; i++) {
        fireworks[i].update();
        fireworks[i].draw(colors[i].r + colorR, colors[i].g + colorG,colors[i].b + colorB);
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
