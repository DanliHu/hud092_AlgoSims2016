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
    
    //    glLineWidth(1.8f);
    
    xoff = 0;
    yoff = 0;
    
    black = true;
    autoMode = true;
    motionMode = false;
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

    
    for(int i=0; i<myRects.size(); i++){
        myRects[i].update();
        if(myRects[i].size > ofGetWidth()*2){
            myRects.erase(myRects.begin());
        }
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
    
    //cam
    vidGrabber.draw(camWidth/2, camHeight/2);
    
    for(unsigned int i = 0; i < finder.blobs.size(); i++)
    {
        ofRectangle cur = finder.blobs[i].boundingRect;
        // ofDrawRectangle(cur.x, cur.y, cur.width, cur.height);
        xOff = ofMap(cur.x, 0, camWidth, 0, ofGetWidth());
        
        cout << cur.x << endl;
    }
    
    //Setup new rect
    if(ofGetFrameNum()%8 == 0){
        
        //autoMode
        if(autoMode) {
            
            Rectangle temp;
            //      float x = (ofNoise(xoff)*ofGetWidth())-ofGetWidth()/2;
            //      float y = (ofNoise(yoff)*ofGetHeight())-ofGetHeight()/2;
            
            float x = (ofNoise(xoff)*ofGetWidth());
            float y = (ofNoise(yoff)*ofGetHeight());
            
            temp.setup(ofPoint(x,y), 1);
            myRects.push_back(temp);
            
        }
        
        //motionMode
        if(motionMode){
            
                //Setup Rect
                Rectangle temp;
                // float x = ofGetWidth()-mouseX;
                float x = xOff;
                // float y = mouseY;
                
                temp.setup(ofPoint(x,ofGetHeight()/2), 1);
                myRects.push_back(temp);
        }
        

            
        //move on x
        if (ofGetFrameNum()>150) {
            xoff += 0.02;
            
            //move on x & y
            if (ofGetFrameNum()>500) {
                xoff += 0.02;
                yoff += 0.005;
            }
        }
    }

    //Rotating (OFF)
    for (int i=0; i<myRects.size(); i++) {
        
//        ofPushMatrix();
//        float count = ofGetElapsedTimef();
//        
//        if (count > 10) {
//            count = 10;
//        }
//        ofRotate(count*sin(ofGetElapsedTimef()));
        
        //Draw rect
        myRects[i].draw();
        
        ///Draw lines
        //        if(i % 2 == 0){
        if(i>=1){
            ofDrawLine(myRects[i].topLeft(),myRects[i-1].topLeft());
            ofDrawLine(myRects[i].topRight(),myRects[i-1].topRight());
            ofDrawLine(myRects[i].bottomLeft(),myRects[i-1].bottomLeft());
            ofDrawLine(myRects[i].bottomRight(),myRects[i-1].bottomRight());
        }
//        ofPopMatrix();
    }
    
    ofDrawBitmapString("Press 1 : Auto Mode", 10, 260);
    ofDrawBitmapString("Press 2 : Motion Mode", 10, 280);
//    ofDrawBitmapString("Press SPACE : Black/White", 10, 300);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == ' '){
        black = !black;
    }
    
    if(key == '1'){
        autoMode = true;
        motionMode = false;
    }
    
    if(key == '2'){
        motionMode = true;
        autoMode = false;
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
