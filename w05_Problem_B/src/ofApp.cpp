#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    ofSetBackgroundAuto(false);
    
    anchor1 = ofVec2f(ofGetWidth()/2-200,ofGetHeight()/2);
    anchor2 = ofVec2f(ofGetWidth()/2+200,ofGetHeight()/2);
    
    ball = ofVec2f(ofGetWidth()/2,ofGetHeight()/2);
    
    dragging = false;
    
    gui.setup("Springs");
    gui.add(k1Slider.setup("k1",0.1,0.01,1));
    gui.add(k2Slider.setup("k2",0.1,0.01,1));
    gui.add(restLength1Slider.setup("restlength1",200,50,400));
    gui.add(restLength2Slider.setup("restlength2",200,50,400));

}

//--------------------------------------------------------------
void ofApp::applyForce(ofVec2f _force){
    
    acc.x += _force.x;
    acc.y += _force.y;
    
}
//--------------------------------------------------------------
void ofApp::update(){
    
    k1 = k1Slider;
    k2 = k2Slider;
    restLength1 = restLength1Slider;
    restLength2 = restLength2Slider;
    
    if (dragging) {
        return;
    }
    
    ofVec2f force1 = ball - anchor1;
    ofVec2f force2 = ball - anchor2;
    
    float currentLength1 = force1.length();
    float currentLength2 = force2.length();
    
    float x1 = currentLength1 - restLength1;
    float x2 = currentLength2 - restLength2;
    
    force1.normalize();
    force2.normalize();
    
    force1 *= -1 * k1 * x1;
    force2 *= -1 * k2 * x2;
    
    applyForce(force1);
    applyForce(force2);
    applyForce(ofVec2f(0,1.0));
    
    vel+=acc;
    vel*=0.98; // gravity
    ball+=vel;
    acc*=0;
    
    count += 0.1;
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(0,10);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    //    ofSetColor(0);
    
    //    ofDrawCircle(anchor1, 10);
    //    ofDrawCircle(anchor2, 10);
    
    //    ofSetColor(200,50,sin(count)*100+100);
    
    ofSetColor(100);
    
    ofDrawLine(anchor1, ball);
    ofDrawLine(anchor2, ball);
    
    ofSetColor(200,50,sin(count)*100+100);
    
    ofDrawCircle(ball, size);
    
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
    
    if(dragging==true){
        ball.set(x, y);
    }
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    if(ofVec2f(x,y).distance(ball) < 100){
        ball.set(x, y);
        dragging = true;
        vel *= 0;
        
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    dragging = false;
    
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
