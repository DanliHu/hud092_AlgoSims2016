#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    img.load("Phoenix1.jpg");
    
    for (int x=0; x<img.getWidth(); x++) {
        for (int y=0; y<img.getHeight(); y++) {

//            ofColor temp;
//            temp = ofColor(img.getColor(x, y));
//            color.push_back(temp);
//
//            Particle tempP;
//            tempP.setup(x, y, img.getWidth(), img.getHeight());
//            particles.push_back(tempP);
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    int time = ofGetElapsedTimef();
    
    for (int x=0; x<img.getWidth(); x++) {
        for (int y=0; y<img.getHeight(); y++) {
            
            loc = x + y * img.getWidth();
            particles[loc].update();
            particles[loc].pile();
            
            if (!mouseMove) {
                particles[loc].falling();
            }
            
            if(mouseMove){
                particles[loc].updateAttraction(particles);
                particles[loc].seek(ofPoint(mouseX,mouseY));
                particles[loc].arrive(ofPoint(mouseX,mouseY));
            }
        }
    }
    cout << color.size() <<endl;
    
//    for (int i=0; i<particles.size(); i++) {
//        particles[i].updateAttraction(particles);
//        particles[i].seek(ofPoint(mouseX,mouseY));
//        particles[i].arrive(ofPoint(mouseX,mouseY));
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
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    mouseMove = true;
    
//    for(int i=0; i<particles.size();i++){
//        loc = x + y * img.getWidth();
//        
//        particles[loc].updateAttraction(particles);
//        particles[loc].seek(ofPoint(x,y));
//        particles[loc].arrive(ofPoint(x,y));
//    }
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
