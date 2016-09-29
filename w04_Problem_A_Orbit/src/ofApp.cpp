#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    
    ofBackground(0);
    maxSize = 300;
    minSize = 20;
    maxSpeed = 0.005;
    minSpeed = 0.0005;
    
    for (int i=0; i<num; i++) {
        Particle temp;
        temp.set(ofRandom(minSize, maxSize), ofRandom(0, 360));
        particles.push_back(temp);
        
        color.push_back(ofColor(ofRandom(80,200),ofRandom(100,150),ofRandom(200,250)));
    }
    
    gui.setup();
//    gui.add(numberSlider.setup("Number of Stars", 2000, 1000, 3000));
//    gui.add(sizeSlider.setup("Size of the Galaxy",300,100,500));
    gui.add(blackHole.setup("Size of the BlackHole",20,10,100));

}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetColor(0,25);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    for (int i=0; i<num; i++) {
        particles[i].update(ofRandom(minSpeed,maxSpeed),  ofPoint(ofGetWidth()*0.5, ofGetHeight()*0.5));
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i=0; i<num; i++) {
        particles[i].draw(color[i]);
        
        if(particles[i].radius < blackHole){
            particles[i].restart(maxSize);
        }
    }
    
    gui.draw();

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
