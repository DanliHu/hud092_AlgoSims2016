#pragma once

#include "ofMain.h"
#include "rectangle.hpp"
#include "ofxCvHaarFinder.h"
#include "mode1.hpp"
#include "mode2.hpp"
#include "star.hpp"

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
    
    mode1 rectMode1;
    mode2 dotMode2;
    
    vector<Star> stars;
    int num;
    
    int mode;
    
    bool black;
    bool autoMode;
    bool motionMode;
    
    ofVideoGrabber vidGrabber;
    ofxCvHaarFinder finder;
    ofPixels img1, img2;
    
    int camWidth, camHeight;
    
    float xOff, yOff; //from cam
    
};
