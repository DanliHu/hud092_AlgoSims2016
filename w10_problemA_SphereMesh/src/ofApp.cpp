#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    rad = 200;
    sphere.setRadius(rad);
    sphere.setResolution(40);
    sphere.setPosition(0,0,0);
    
    vertices = sphere.getMesh().getVertices();
    
    for (int i=0; i<vertices.size(); i++) {
        ofPoint p;
        p = sphere.getMesh().getVertex(i);
        vertex.push_back(p);
        
        float tempT;
        theta.push_back(tempT);
        
        float tempP;
        phi.push_back(tempP);
        
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    float time = ofGetElapsedTimef();
    
    for (int i=0; i<vertex.size(); i++) {

        vertex[i] = sphere.getMesh().getVertex(i);
        
        float x = vertex[i].x;
        float y = vertex[i].y;
        float z = vertex[i].z;
        
        theta[i] = atan(sqrt(pow(x, 2)+pow(y, 2))/z);
        phi[i] = atan(y/x);

        float perlin = ofNoise(i*0.05, i*0.02, time *0.5);
        
        vertex[i].x = (rad+perlin*50)*sin(theta[i])*cos(phi[i]);
        vertex[i].y = (rad+perlin*50)*sin(theta[i])*sin(phi[i]),
        vertex[i].z = (rad+perlin*50)*cos(theta[i]);
        
        sphere.getMesh().setVertex(i, vertex[i]);
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    cam.begin();
    
    sphere.drawWireframe();
    
    cout<< vertex.size()<<endl;
    
    cam.end();

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
