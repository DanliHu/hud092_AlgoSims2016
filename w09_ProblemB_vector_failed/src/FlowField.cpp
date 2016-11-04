//
//  FlowField.cpp
//  vectorPic
//
//  Created by Danli Hu on 11/3/16.
//
//

#include "FlowField.hpp"

void FlowField::setup( int width, int height, int res ) {
    fieldWidth = width;
    fieldHeight = height;
    resolution = res;
    
    int cols = fieldWidth / resolution;
    int rows = fieldHeight / resolution;

    for (int i=0; i<cols; i++) {
        vector<ofVec2f> temp;
        flowList.push_back(temp);
        
        for(int j=0; j<rows; j++){
            ofVec2f tempP = ofVec2f(0,0);
            flowList[i].push_back(tempP);
        }
    }
}

void FlowField::applyImg(float _brightness){
    for( int i=0; i<flowList.size(); i++){
        for( int j=0; j<flowList[i].size(); j++){
            float angle = ofMap(_brightness, 0, 255, 0, 2*PI);
            flowList[i][j].set(ofVec2f(cos(angle),sin(angle)));
        }
    }
}


void FlowField::draw(){
    for( int i=0; i<flowList.size(); i++){
        for( int j=0; j<flowList[i].size(); j++){
            ofVec2f np( i*resolution, j*resolution );
            drawVectorAt( flowList[i][j], np );
        }
    }
}

void FlowField::drawVector( const ofVec3f &start, const ofVec3f &end, float headLength, float headRadius ) {
    const int NUM_SEGMENTS = 32;
    float lineVerts[3*2];
    ofVec3f coneVerts[NUM_SEGMENTS+2];
    glEnableClientState( GL_VERTEX_ARRAY );
    glVertexPointer( 3, GL_FLOAT, 0, lineVerts );
    lineVerts[0] = start.x; lineVerts[1] = start.y; lineVerts[2] = start.z;
    lineVerts[3] = end.x; lineVerts[4] = end.y; lineVerts[5] = end.z;
    glDrawArrays( GL_LINES, 0, 2 );
    
    // Draw the cone
    ofVec3f axis = ( end - start ).normalized();
    ofVec3f temp = ( axis.dot( ofVec3f(0,1,0) ) > 0.999f ) ? axis.crossed( ofVec3f(1,0,0) ) : axis.crossed( ofVec3f(0,1,0) );
    ofVec3f left = ofVec3f(axis.crossed( temp )).normalized();
    ofVec3f up = axis.crossed( left ).normalized();
    
    glVertexPointer( 3, GL_FLOAT, 0, &coneVerts[0].x );
    coneVerts[0] = ofVec3f( end + axis * headLength );
    for( int s = 0; s <= NUM_SEGMENTS; ++s ) {
        float t = (float)s / (float)NUM_SEGMENTS;
        coneVerts[s+1] = ofVec3f( end + left * headRadius * cos( t * 2.0f * 3.14159f )
                                 + up * headRadius * sin( t * 2.0f * 3.14159f ) );
    }
    glDrawArrays( GL_TRIANGLE_FAN, 0, NUM_SEGMENTS+2 );
    
    // draw the cap
    glVertexPointer( 3, GL_FLOAT, 0, &coneVerts[0].x );
    coneVerts[0] = end;
    for( int s = 0; s <= NUM_SEGMENTS; ++s ) {
        float t = s / (float)NUM_SEGMENTS;
        coneVerts[s+1] = ofVec3f( end - left * headRadius * (float)cos( t * 2 * 3.14159f )
                                 + up * headRadius * (float)sin( t * 2 * 3.14159f ) );
    }
    glDrawArrays( GL_TRIANGLE_FAN, 0, NUM_SEGMENTS+2 );
    
    glDisableClientState( GL_VERTEX_ARRAY );
}

void FlowField::drawVectorAt( const ofVec2f &vec, const ofVec2f &pos ) {
    ofVec2f np = pos - (vec.normalized()) * 5.0;
    drawVector( np, np + vec.normalized() * 10.0, 5, 3 );
}

