#include "ofApp.h"


float lastdistance = 0;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    bool hasDrawn = false;
    ofRectMode(RECT_MODE_CENTER);
    season = 0;
    /*
     0 = SUMMER
     1 = FALL
     2 = WINTER
     3 = SPRING
     
     */
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    img.draw(0, 0, ofGetWidth(),ofGetHeight());
//    ofSetColor(0, 0, 0);
//    ofRect(0,0, ofGetWidth()/2, ofGetHeight()/2);
    
////Learning the angles of the OF world ....
//    ofSetColor(255,0,0);
//    ofSetLineWidth(30);
//    ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2 + 50*(cos(0)), ofGetHeight()/2 + 50*(sin(0)));
//    
//    ofSetColor(0,255,0);
//    ofSetLineWidth(30);
//    ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2 + 50*(cos(PI/4)), ofGetHeight()/2 + 50*(sin(PI/4)));
//    
//    ofSetColor(0,0,255);
//    ofSetLineWidth(30);
//    ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2 + 50*(cos(PI/2)), ofGetHeight()/2 + 50*(sin(PI/2)));
//    
//    
//    
//    ofSetColor(255,0,0);
//    ofSetLineWidth(5);
//    ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2 + 100*(cos(3*(PI/4))), ofGetHeight()/2 + 100*(sin(3*(PI/4))));
//    
//    ofSetColor(0,255,0);
//    ofSetLineWidth(5);
//    ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2 + 100*(cos(PI)), ofGetHeight()/2 + 100*(sin(PI)));
//    
//    ofSetColor(0,0,255);
//    ofSetLineWidth(5);
//    ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2 + 100*(cos(5*(PI/4))), ofGetHeight()/2 + 100*(sin(5*(PI/4))));
//    
//    
//    
//    ofSetColor(255,0,0);
//    ofSetLineWidth(1);
//    ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2 + 200*(cos(3*(PI/2))), ofGetHeight()/2 + 200*(sin(3*(PI/2))));
//    
//    ofSetColor(0,255,0);
//    ofSetLineWidth(1);
//    ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2 + 200*(cos(7*(PI/4))), ofGetHeight()/2 + 200*(sin(7*(PI/4))));
//    
//    ofSetColor(0,0,255);
//    ofSetLineWidth(1);
//    ofLine(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()/2 + 200*(cos(2*PI)), ofGetHeight()/2 + 200*(sin(2*PI)));

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    ofBackgroundGradient(ofColor::yellowGreen, ofColor(255,255,255), OF_GRADIENT_CIRCULAR);
    
    
    if(key == OF_KEY_RIGHT){
        season = 0;
        ofPushStyle();
        myBranch.setup(ofGetWidth()/2,      //float _xPos
                       3*(ofGetHeight()/4),     //float _yPos
                       //                   ofGetHeight()/2,     //float _yPos
                       20,                  //float _width
                       70,                  //float _length
                       0.35,                //float _splitPercentage
                       PI/4,                //float _maxSplitAngle
                       2,                   //int _maxSubdivisions
                       5,                   //int _maxSegments
                       0,                   //int _segmentsSinceStart
                       -PI/2,                //float _angle
                       0,                   //float _curvature
                       ofColor(73, 36, 13),//ofColor _color
                       season,
                       5);                  //int numberOfBobs
        img.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR_ALPHA);
        img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        ofPopStyle();
        
        
    }
    
    if(key == OF_KEY_LEFT){
        season = 1;
        ofPushStyle();
        myBranch.setup(ofGetWidth()/2,      //float _xPos
                       3*(ofGetHeight()/4),     //float _yPos
                       //                   ofGetHeight()/2,     //float _yPos
                       20,                  //float _width
                       70,                  //float _length
                       0.35,                //float _splitPercentage
                       PI/4,                //float _maxSplitAngle
                       2,                   //int _maxSubdivisions
                       5,                   //int _maxSegments
                       0,                   //int _segmentsSinceStart
                       -PI/2,                //float _angle
                       0,                   //float _curvature
                       ofColor(73, 36, 13),//ofColor _color
                       season,
                       5);                  //int numberOfBobs
        img.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR_ALPHA);
        img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        ofPopStyle();
    }
    
    
    if(key == OF_KEY_UP){
        season = 2;
        ofPushStyle();
        myBranch.setup(ofGetWidth()/2,      //float _xPos
                       3*(ofGetHeight()/4),     //float _yPos
                       //                   ofGetHeight()/2,     //float _yPos
                       20,                  //float _width
                       70,                  //float _length
                       0.35,                //float _splitPercentage
                       PI/4,                //float _maxSplitAngle
                       2,                   //int _maxSubdivisions
                       5,                   //int _maxSegments
                       0,                   //int _segmentsSinceStart
                       -PI/2,                //float _angle
                       0,                   //float _curvature
                       ofColor(73, 36, 13),//ofColor _color
                       season,
                       5);                  //int numberOfBobs
        
        img.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR_ALPHA);
        img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        ofPopStyle();
    }
    
    if(key == OF_KEY_DOWN){
        season = 3;
        ofPushStyle();
        myBranch.setup(ofGetWidth()/2,      //float _xPos
                       3*(ofGetHeight()/4),     //float _yPos
                       //                   ofGetHeight()/2,     //float _yPos
                       20,                  //float _width
                       70,                  //float _length
                       0.35,                //float _splitPercentage
                       PI/4,                //float _maxSplitAngle
                       2,                   //int _maxSubdivisions
                       5,                   //int _maxSegments
                       0,                   //int _segmentsSinceStart
                       -PI/2,                //float _angle
                       0,                   //float _curvature
                       ofColor(73, 36, 13),//ofColor _color
                       season,
                       5);                  //int numberOfBobs
        img.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR_ALPHA);
        img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        ofPopStyle();
    }
    


}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

//    float distance = ofDist(500, 300, x, y);
//    
//    
//    if(distance > lastdistance)
//    {
//        for(int i=0; i<NUM_STARS; i++)
//        {
//            StarRad[i] += 4;
//            
//            StarB[i] += 4;
//        }
//    }
//    
//    else
//    {
//        for(int i=0; i<NUM_STARS; i++)
//        {
//            StarRad[i] -= 4;
//            
//            StarB[i] -= 4;
//        }
//    }
//    
//    lastdistance = distance;

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    ofBackgroundGradient(ofColor::yellowGreen, ofColor(255,255,255), OF_GRADIENT_CIRCULAR);
    
    //This is where your Tree begins!
    myBranch.setup(ofGetWidth()/2,      //float _xPos
                   3*(ofGetHeight()/4),     //float _yPos
//                   ofGetHeight()/2,     //float _yPos
                   20,                  //float _width
                   70,                  //float _length
                   0.35,                //float _splitPercentage
                   PI/4,                //float _maxSplitAngle
                   2,                   //int _maxSubdivisions
                   5,                   //int _maxSegments
                   0,                   //int _segmentsSinceStart
                   -PI/2,                //float _angle
                   0,                   //float _curvature
                   ofColor(73, 36, 13),//ofColor _color
                   false,
                   5);                  //int numberOfBobs
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
