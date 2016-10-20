#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofFill();
    ofSetCircleResolution(100);
    
    ofBackground(0);
    ofSetBackgroundAuto(false);

    radius = 300;
    angle = 0;
    step = 0.0002;
    
    //group1
    for(int i=0; i<num; i++){
        Vehicle temp;
        vehicles1.push_back(temp);
    }
    
    //group2
    for(int i=0; i<num; i++){
        Vehicle temp;
        vehicles2.push_back(temp);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    ofFill();
    
    //group1
    for(int i=0; i<num; i++){
        angle += step;
        
        float x = ofGetWidth()/2 + radius * cos(angle);
        float y = ofGetHeight()/2 + radius * sin(angle);
        
        vehicles1[i].update(&vehicles1);
        vehicles1[i].seek(ofPoint(x,y));
        vehicles1[i].arrive(ofPoint(x,y));
        vehicles1[i].addRepulsionForce(ofPoint(mouseX,mouseY));
        
        ofSetColor(255, 0, 0);
        
        if(displayTarget){
        ofDrawCircle(x,y,1);
        }
    }
    
    //group2
    for(int i=0; i<num; i++){
        angle += step;
        
        float x = ofGetWidth()/2 + radius * cos(angle + PI);
        float y = ofGetHeight()/2 + radius * sin(angle + PI);
        
        vehicles2[i].update(&vehicles2);
        vehicles2[i].seek(ofPoint(x,y));
        vehicles2[i].arrive(ofPoint(x,y));
        vehicles2[i].addRepulsionForce(ofPoint(mouseX,mouseY));
        
        ofSetColor(255, 0, 0);
        
        if(displayTarget){
        ofDrawCircle(x,y,1);
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofFill();
    
    ofSetColor(0,12);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    ofSetColor(255);
    
    //group1
    for(int i=0; i<num; i++){
        vehicles1[i].display();
    }
    
    //group2
    for(int i=0; i<num; i++){
        vehicles2[i].display();
    }
    
    float preMouseX = ofGetPreviousMouseX();
    float preMouseY = ofGetPreviousMouseY();
    
    float speed = ofDist(mouseX, mouseY, preMouseX, preMouseY);
    //    cout<< speed << endl;
    
    if(ofGetFrameNum()%10 == 0){
        Ripple temp;
//        temp.setup(mouseX, mouseY);
        ripples.push_back(temp);
        
        for (int i=0; i<ripples.size(); i++) {
            ripples[i].setup(mouseX, mouseY);
//            ripples[i].update(speed);
            ripples[i].draw(speed);
        }
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
    
    displayTarget = !displayTarget;
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
