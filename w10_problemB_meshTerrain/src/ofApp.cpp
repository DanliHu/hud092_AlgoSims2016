#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    height = 100;
    gridWidth = 200;
    gridHeight = 200;
    
    image.load("img.jpg");
//    image.resize(200, 200);
    
    int scale = 6;
    
    mesh.setMode(OF_PRIMITIVE_LINES);
    
    w = image.getWidth();
    h = image.getHeight();
    
    
    for (int x=0; x<w; x++) {
        for (int y=0; y<h; y++) {
            
            ofColor c = image.getColor(x, y);
            
            float disRed = ofDist(c.r, c.g, c.b, 255,0,0);
            float z = ofMap(disRed, 255,0, -height, height);
            
//            ofVec3f pos(4*x, 4*y, z);
            ofVec3f pos(x, y, z);
            mesh.addVertex(pos);
            mesh.addColor(c);
        }
    }
    
    // Let's add some lines!
//    float connectionDistance = 20;
//    int numVerts = mesh.getNumVertices();
//    for (int a=0; a<numVerts; a++) {
//        ofVec3f verta = mesh.getVertex(a);
//        for (int b=a+1; b<numVerts; b++) {
//            ofVec3f vertb = mesh.getVertex(b);
//            float distance = verta.distance(vertb);
//            if (distance <= connectionDistance) {
//                mesh.addIndex(a);
//                mesh.addIndex(b);
//            }
//        }
//    }
    
    //WATER
    for(int y = 0; y< gridWidth; y++){
        for(int x = 0; x < gridHeight; x++){
            
            //create our mesh:
            water.addVertex(ofPoint(
                                   (x-gridWidth*0.5)*scale,
                                   (y-gridHeight*0.5)*scale,
                                   0));
            water.addColor(ofColor(100,150,255));
        }
    }
    
    for(int y=0; y < gridWidth-1; y++){
        for(int x=0; x< gridHeight-1; x++){
            //loop through the squares to get the indices
            i1 = x + gridWidth * y;
            i2 = x+1 + gridWidth * y;
            i3 = x + gridWidth * (y+1);
            i4 = x+1 + gridWidth * (y+1);
            
            water.addTriangle(i1, i2, i3);
            water.addTriangle(i2, i3, i4);
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    float time = ofGetElapsedTimef();
    
    for(int y = 0; y< gridWidth; y++){
        for(int x = 0; x < gridHeight; x++){
            int i = x + gridWidth *y;
            
            ofPoint p = water.getVertex(i);
            
            float perlin = ofNoise(x*0.05, y*0.05, time *0.5);
            p.z = perlin * 10 - height/2;
            
            water.setVertex(i, p);
            water.setColor(i, ofColor(perlin*30+100, perlin*30+150, 230));
            
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofColor centerColor = ofColor(100,150,255);
    ofColor edgeColor(85, 78, 68);
    ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);
    
    image.draw(10, 10);
    image.resize(w/10, h/10);
    
    easyCam.begin();
    
    water.drawWireframe();
    
    ofPushMatrix();
    ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
    mesh.draw();
    ofPopMatrix();
    

    
    easyCam.end();
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
