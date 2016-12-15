//
//  mode2.cpp
//  zooming3_webCam
//
//  Created by Danli Hu on 12/15/16.
//
//

#include "mode2.hpp"

void mode2::update(){
    for (int i = 0; i < myDots.size(); i++) {
        myDots[i].update(5*ofNoise(ofGetElapsedTimef()));
        if(myDots[i].pos1.x > ofGetWidth()*2){
            myDots.erase(myDots.begin());
        }
    }
    
    for (int i = 0; i < myDots2.size(); i++) {
        myDots2[i].update(2*ofNoise(ofGetElapsedTimef()+2));
        if(myDots2[i].pos1.x > ofGetWidth()*2){
            myDots2.erase(myDots2.begin());
        }
    }
    
    for (int i = 0; i < myDots3.size(); i++) {
        myDots3[i].update(ofNoise(ofGetElapsedTimef()+10));
        if(myDots3[i].pos1.x > ofGetWidth()*2){
            myDots3.erase(myDots3.begin());
        }
    }
}

void mode2::draw(bool _autoMode, bool _motionMode, float _xOff){
    
    
    if(ofGetFrameNum()%2 == 0){
        
            if(_autoMode){
        Dots temp;
        temp.setup(ofPoint(ofGetWidth()/2,ofGetHeight()/2));
        myDots.push_back(temp);
        myDots2.push_back(temp);
        myDots3.push_back(temp);
            }
        
        if (_motionMode) {
            Dots temp;
            float x = _xOff;
            
            temp.setup(ofPoint(x,ofGetHeight()/2));
//            temp.setup();
            myDots.push_back(temp);
            myDots2.push_back(temp);
            myDots3.push_back(temp);
        }
    
    }
    for (int i = 0; i < myDots.size(); i++) {
        myDots[i].draw();
        
        if(i>=1){
            ofDrawLine(myDots[i].pos1,myDots[i-1].pos1);
            ofDrawLine(myDots[i].pos2,myDots[i-1].pos2);
            ofDrawLine(myDots[i].pos3,myDots[i-1].pos3);
        }
    }
    
    for (int i = 0; i < myDots2.size(); i++) {
        myDots2[i].draw();
        
        if(i>=1){
            ofDrawLine(myDots2[i].pos1,myDots2[i-1].pos1);
            ofDrawLine(myDots2[i].pos2,myDots2[i-1].pos2);
            ofDrawLine(myDots2[i].pos3,myDots2[i-1].pos3);
        }
    }
    
    for (int i = 0; i < myDots3.size(); i++) {
        myDots3[i].draw();
        
        if(i>=1){
            ofDrawLine(myDots3[i].pos1,myDots3[i-1].pos1);
            ofDrawLine(myDots3[i].pos2,myDots3[i-1].pos2);
            ofDrawLine(myDots3[i].pos3,myDots3[i-1].pos3);
        }
    }

}