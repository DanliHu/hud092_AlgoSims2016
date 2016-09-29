#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetCircleResolution(100);
    
    ptsW = 30;
    ptsH = 30;
    
    repulsionPos.set(ofGetWidth()/2-100,ofGetHeight()/2);
    attractionPos.set(ofGetWidth()/2+100,ofGetHeight()/2);
    
    for (int i=0; i<ptsW; i++) {
        for (int j=0; j<ptsH; j++) {
            float x = ofMap(i, 0, ptsW, 0, ofGetWidth());
            float y = ofMap(j, 0, ptsH, 0, ofGetHeight());
            
            Particle temp;
            temp.setInitial(ofPoint(x,y), ofPoint(0,0));
            particles.push_back(temp);
        }
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    int count = 0;
    for (int i=0; i<ptsW; i++) {
        for (int j=0; j<ptsH; j++) {
            float x = ofMap(i, 0, ptsW, 0, ofGetWidth());
            float y = ofMap(j, 0, ptsH, 0, ofGetHeight());
            
            particles[count].resetForce();
            particles[count].addRepulsionForce(repulsionPos, 80, 0.02);
            particles[count].addAttractionForce(attractionPos, 80, 0.02);
            particles[count].addDamping();
            particles[count].update();
            
            count ++;
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(255);
    ofSetColor(0);
    for (int i=0; i<particles.size(); i++) {
        particles[i].draw();
    }
    
    ofSetColor(255, 0, 0);
    ofDrawCircle(repulsionPos, radius);
    
    ofSetColor(0, 0, 255);
    ofDrawCircle(attractionPos, radius);
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
    float distance = ofDist(x, y, repulsionPos.x,repulsionPos.y);
    float inBetween = ofDist(repulsionPos.x, repulsionPos.y, attractionPos.x, attractionPos.y);
    
    if(distance < radius){
        repulsionPos.x = x;
        repulsionPos.y = y;
    }
    
    float distance2 = ofDist(x, y, attractionPos.x,attractionPos.y);
    if(distance2 < radius){
        attractionPos.x = x;
        attractionPos.y = y;
    }
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
