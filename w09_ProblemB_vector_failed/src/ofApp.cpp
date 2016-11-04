#include "ofApp.h"

//--------------------------------------------------------------
//BROKEN CODE:

//I was trying to set the angle of the vector based on the brightness from an image. So the particles could follow the edge of an image.
//But the structure of vector field confused me.
//Will try to figure out later.

//--------------------------------------------------------------

void ofApp::setup(){
    res = 20;
    
    img.load("img.jpg");
    
    cols = ofGetWidth() / res;
    rows = ofGetHeight() / res;
//
    for (int i=0; i<cols; i++) {
        for (int j=0; j<rows; j++) {
            ofColor temp = ofColor(img.getColor(i*res, j*res));
            colors.push_back(temp);

            FlowField tempF;
            tempF.setup(ofGetWidth(), ofGetHeight(), res);
            myField.push_back(tempF);
        }
    }
    
//    myField.setup(ofGetWidth(), ofGetHeight(), res);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    img.draw(0,0);
    
    for (int i=0; i<colors.size(); i++) {

        myField[i].applyImg(colors[i].getBrightness());
        myField[i].draw();
//
//            myField.applyImg(colors[i].getBrightness());
//            myField.draw();
        
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
