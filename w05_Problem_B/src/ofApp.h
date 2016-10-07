#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    void applyForce(ofVec2f _force);
    float k1, k2;
    float restLength1, restLength2 ;
    
    ofVec2f acc, vel;
    ofVec2f anchor1, anchor2, ball;
    
    float size = 5;
    float count = 0;
    
    bool dragging;
    
    ofxFloatSlider k1Slider, k2Slider, restLength1Slider, restLength2Slider;
    
    ofxPanel gui;
    
};
