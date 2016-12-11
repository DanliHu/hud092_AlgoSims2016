#pragma once

#include "ofMain.h"
#include "rectangle.hpp"
#include "ofxCvHaarFinder.h"

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
    
    vector<Rectangle> myRects;
    int num;
    
    bool black;
    float xoff, yoff;
    
    bool autoMode;
    bool motionMode;
    
    ofVideoGrabber vidGrabber;
    ofxCvHaarFinder finder;
    ofPixels img1, img2;
    
    int camWidth, camHeight;
    
    float xOff, yOff;
    
};
