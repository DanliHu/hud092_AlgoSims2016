#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
//    gui.setup();
//    gui.add(numSlider.setup("Number of Cars",3,1,10));
//    num = numSlider;
    
    num = 10;
    
    for (int i=0; i<num; i++) {
        ofPoint tempDest;
        dests.push_back(tempDest);
        dests[i] = ofPoint( ofRandomWidth(), ofRandomHeight() );
        
        
        Particle tempCar;
        cars.push_back(tempCar);
        cars[i].setInit(ofGetWindowSize() / 2, ofPoint(ofRandom(-10.10), ofRandom(-5, 5)));
        
        
        colors.push_back(ofColor(ofRandom(255),ofRandom(255),ofRandom(255)));
        cars[i].color = colors[i];
    }

    
    ofBackground(255);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    

    for (int i=0; i<num; i++) {
        cars[i].seek(dests[i]);
        
        float area = 200;
        int nextCar = i+1;
        
        if (nextCar>num) {
            nextCar=0;
        }
        
        if(cars[i].getPosition().distance(cars[nextCar].getPosition())<area){
            cars[i].color = ofColor(255,0,0);
            cars[nextCar].color = ofColor(255,0,0);
        }else{
            cars[i].color = colors[i];
        }
        
        cars[i].update();
        
        if (cars[i].getPosition().distance(dests[i])<5) {
            dests[i] = ofPoint( ofRandomWidth(), ofRandomHeight() );
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    
    for (int i=0; i<num; i++) {
        ofSetColor(cars[i].color);
        ofDrawCircle(dests[i],4);
        cars[i].draw();
    }
    
    string someString("Number of Cars: ");
    printf("%s\n",someString.c_str());
    cout<< num <<endl ;
    
//    gui.draw();
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
