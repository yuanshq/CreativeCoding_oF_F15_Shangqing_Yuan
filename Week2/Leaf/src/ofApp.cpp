#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableAlphaBlending(); //allows you to use transparent colors
    ofEnableSmoothing(); //make lines smoooooooooth...
    
    numLeaves = (int)ofRandom(5,15);
    for (int i = 0; i < numLeaves; i++){
        leaf tempLeaf;
        tempLeaf.setup();
        leaves.push_back(tempLeaf); // add a leaf with value tempLeaf to the end of vector
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < numLeaves; i++){
        leaves[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < numLeaves; i++){
        leaves[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    leaves.clear(); //clear removes all elements in the vector reducing its size to 0.
    setup();

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
