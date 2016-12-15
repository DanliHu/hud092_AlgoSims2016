//
//  mode1.cpp
//  zooming3_webCam
//
//  Created by Danli Hu on 12/15/16.
//
//

#include "mode1.hpp"

void mode1::setup(){
    xoff = 0;
    yoff = 0;
}

void mode1::update(){
    
    for(int i=0; i<myRects.size(); i++){
        myRects[i].update();
        if(myRects[i].size > ofGetWidth()*2){
            myRects.erase(myRects.begin());
        }
    }
    
}

void mode1::draw(bool _autoMode, bool _motionMode, float _xOff){
    
    if(ofGetFrameNum()%8 == 0){
        
        //autoMode
        if(_autoMode) {
            
            Rectangle temp;
            
            float x = (ofNoise(xoff)*ofGetWidth());
            float y = (ofNoise(yoff)*ofGetHeight());
            
            temp.setup(ofPoint(x,y), 1);
            myRects.push_back(temp);
            
        }
        
        //motionMode
        if(_motionMode){
            
            //Setup Rect
            Rectangle temp;
            float x = _xOff;
            
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

}