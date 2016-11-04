#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofBackground(120,100,180);
    
    resolution = 10;
    
    gui.setup();
    gui.add(offset.setup("offset",5,0,10));
    
    cols = ofGetWidth()/resolution;
    rows = ofGetHeight()/resolution;
    
    yOff = 0;
    
    offset2 = 100;
    
    for (int i = 0; i < cols; i++) {
        xOff = 0;
        
        vector<Individual> temp;
        table.push_back(temp);
        
        vector<Individual> temp2;
        table2.push_back(temp2);
        
        vector<ofColor> tempColor;
        colors.push_back(tempColor);
        
        vector<ofColor> tempColor2;
        colors2.push_back(tempColor2);
        
        for (int j = 0; j < rows; j++) {
            
            Individual tempI;
            tempI.setup(ofPoint(i*resolution ,j*resolution));
            table[i].push_back(tempI);
            
            Individual tempI2;
            tempI2.setup(ofPoint(i*resolution ,j*resolution));
            table2[i].push_back(tempI2);
            
            colors[i].push_back(ofColor(ofNoise(xOff)*255,100,ofNoise(yOff)*255));
            
            colors2[i].push_back(ofColor(ofNoise(xOff)*255,ofNoise(yOff)*255,200));
            
            
            xOff += 0.01;
            
            
        }
        
        yOff += 0.01;
        
    }
    

    
}

//--------------------------------------------------------------
void ofApp::update(){
    cout << offset <<endl;
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    yOff = 0;
    
    for (int i = 0; i < table.size(); i++) {
        xOff = 0;
        for (int j = 0; j < table[i].size(); j++) {
            table[i][j].update(ofNoise(xOff-offset/2,yOff)*1.5*resolution);
            table2[i][j].update(ofNoise(yOff,xOff+offset/2)*resolution);
            
            xOff += 0.01;
        }
        yOff += 0.01;
    }
    
    for (int i = 1; i < cols; i++) {
        for (int j = 1; j < rows; j++) {

            table[i][j].draw(colors[i][j]);
            table2[i][j].draw(colors2[i][j]);
            

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
