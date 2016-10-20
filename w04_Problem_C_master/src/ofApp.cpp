#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    img.load("Phoenix1.jpg");
    
    for (int x=0; x<img.getWidth(); x++) {
        for (int y=0; y<img.getHeight(); y++) {
            
            ofColor temp;
            temp = ofColor(img.getColor(x, y));
            color.push_back(temp);
            
            Particle tempP;
            tempP.setup(x, y, img.getWidth(), img.getHeight());
            particles.push_back(tempP);
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    int time = ofGetElapsedTimef();
    
//    if(time > 1){
//    if(time % 10 == 0){
    for (int x=0; x<img.getWidth(); x++) {
        for (int y=0; y<img.getHeight(); y++) {
            
            loc = x + y * img.getWidth();
            
            particles[loc].update();
        }
      }
//    }
//    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int x=0; x<img.getWidth(); x++) {
        for (int y=0; y<img.getHeight(); y++) {
            
            loc = x + y * img.getWidth();
            
            float sat = color[loc].getSaturation();

            if(color[loc].getBrightness() > thereshold){
            particles[loc].draw(color[loc]);
            }
        }
    }
    
//    img.draw(0, 0);
    
//    cout<<color.size()<<endl;
    cout<<ofGetFrameRate()<<endl;

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
