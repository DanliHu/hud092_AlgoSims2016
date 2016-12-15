#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofNoFill();
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    finder.setup("haarcascade_frontalface_default.xml");
    
    camWidth = 320;
    camHeight = 240;
    
    vidGrabber.setVerbose(true);
    vidGrabber.initGrabber(camWidth,camHeight);
    img1.allocate(camWidth,camHeight,OF_PIXELS_RGB);
    img2.allocate(camWidth, camHeight,OF_PIXELS_RGB);
    
    ofToggleFullscreen();
    
    rectMode1.setup();
    
    black = true;
    autoMode = true;
    motionMode = false;
    
    mode = 1;
}

//--------------------------------------------------------------
void ofApp::update(){
  
    
    vidGrabber.update();
    
    if (vidGrabber.isFrameNew())
    {
        img1.setFromPixels(vidGrabber.getPixels(), 320,240,OF_PIXELS_RGB);
        img2 = img1;
        finder.findHaarObjects(img2);
    }
    
    for (int i=0; i<stars.size(); i++) {
        stars[i].update();
    }
    
    if (mode == 1) {
        rectMode1.update();
    }
    
    if (mode == 2) {
        dotMode2.update();
    }
    
//    cout << myRects.size() << endl;
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //Toggle between black & white
    if (black) {
        ofBackground(0);
        ofSetColor(255);
    }else{
        ofBackground(255);
        ofSetColor(0);
    }
    
    for(unsigned int i = 0; i < finder.blobs.size(); i++)
    {
        ofRectangle cur = finder.blobs[i].boundingRect;
        xOff = ofMap(cur.x, 0, camWidth, 0, ofGetWidth());
        cout << cur.x << endl;
    }
    
    //Setup new rect
    if(mode == 1){
        rectMode1.draw(autoMode, motionMode, xOff);
//        starF.draw();
    }
    
    if(mode == 2){
        dotMode2.draw(autoMode, motionMode, xOff);
    }
    
    if(mode == 3){
        //star Field setup
        num = 100;
        for(int i=0; i<num; i++){
            Star temp;
            temp.setup();
            stars.push_back(temp);
        }
        
        ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        for (int i=0; i<stars.size(); i++) {
            stars[i].draw();
        }
        ofPopMatrix();
    }
    
    ofDrawBitmapString("Press a : Auto Mode/ Motion Mode", 10, 260);
    ofDrawBitmapString("Press SPACE : Black/ White", 10, 280);
    ofDrawBitmapString("Press 1 : Tunnel", 10, 300);
    ofDrawBitmapString("Press 3 : 3D shape", 10, 320);
    ofDrawBitmapString("Press 2 : Star Field", 10, 340);
    
    //cam
    ofSetColor(255);
    vidGrabber.draw(camWidth/2, camHeight/2);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == ' '){
        black = !black;
    }
    
    if(key == 'a'){
        autoMode = !autoMode;
        motionMode = !motionMode;
    }
    
    switch (key) {
        case '1':
            mode = 1;
            break;
            
        case '2':
            mode = 2;
            break;
            
        case '3':
            mode = 3;
            break;
            
        default:
            break;
    }
    
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
