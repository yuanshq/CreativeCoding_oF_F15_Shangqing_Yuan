//
//  leaf.cpp
//  Leaf
//
//  Created by 原上青 on 9/10/15.
//
//

#include "leaf.h"

void leaf::setup(){
    xPos = ofGetWidth()/2;
    yPos = ofGetHeight()/2;
    stemLength = ofRandom(20,50);
    stemWidth = ofRandom(2,4);
    leafLength = ofRandom(100,200);
    leafWidth = ofRandom(80,100);
    
    stemColor = ofColor(ofRandom(100,150),50,20); //brown
    leafColor = ofColor(ofRandom(0,20), ofRandom(100,200), ofRandom(0,20), ofRandom(150,255)); //set to random green color
    scaleFactor = ofRandom(.5,1.0);//ofScale produces a nonuniform scaling along the x, y, and z axes.
    ofSetRectMode(OF_RECTMODE_CENTER);//ofRect(50,50,80,80),the center is (50,50)
    
    leafCurvature = ofRandom(1, 10);//?
    rotation = ofRandom(0, 360);//?
}

//--------------------------------------------------------------
void leaf::update(){
    
}

//--------------------------------------------------------------
void leaf::draw(){
    ofPushMatrix();//ofPushMatrix saves the current coordinate system allowing users to develop specific movements in some graphic objects. ofPopMatrix needs to be called after.
    ofTranslate(xPos, yPos);//ofTranslate produces a translation by (x,y,z) vector of our coordinate system.Use ofPushMatrix and ofPopMatrix to save and restore the untranslated coordinate system.
    ofScale(scaleFactor, scaleFactor);//ofScale produces a nonuniform scaling along the x, y, and z axes.
    ofRotateZ(rotation);//ofRotateZ produces a rotation of angle "degrees" around the Z-axis of our coordinate system represented by the vector (0,0,1). 
    
    //draw leaf
    
    ofSetColor(leafColor);
    
    //draw left part of leaf
    
    ofBeginShape();
    
    float x0 = 0;
    float x1 = x0 - leafWidth;
    float x2 = x0 - leafWidth/leafCurvature;
    float x3 = x0 - leafWidth/3;
    
    float y0 = 0 - stemLength;
    float y1 = y0 - leafLength/3;
    float y2 = y1 - leafLength/3;
    float y3 = y0 - leafLength;
    
    ofVertex(x0,y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    
    ofEndShape();
    
    //draw middle part of leaf
    ofBeginShape();
    
     x0 = 0;
     x1 = x0 - leafWidth;
     x2 = x0 - leafWidth/leafCurvature;
     x3 = x0;
    
     y0 = 0 - stemLength;
     y1 = y0 - leafLength/3;
     y2 = y1 - leafLength/2;
     y3 = y0 - leafLength/2;
    
    ofVertex(x0,y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    
    ofEndShape();
    
    //draw right part of leaf
    
    ofBeginShape();
    
    x0 = 0; 
    x1 = x0 + leafWidth;
    x2 = x0 + leafWidth/leafCurvature;
    x3 = x0 + leafWidth/3;
    
    y0 = 0 - stemLength;
    y1 = y0 - leafLength/3;
    y2 = y1 - leafLength/3;
    y3 = y0 - leafLength;
    
    ofVertex(x0,y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    
    ofEndShape();
    
    //draw stem and veins of leaf
    
    ofSetColor(stemColor);
    ofRect(0,0 - (stemLength/2), stemWidth, stemLength);
    ofTriangle(0 - stemWidth/2, 0 - stemLength, 0 + stemWidth/2, 0 - stemLength, 0, 0 - stemLength - 3*(leafLength/4));
    
    ofPopMatrix();//ofPopMatrix() restores the prior coordinate system.
}