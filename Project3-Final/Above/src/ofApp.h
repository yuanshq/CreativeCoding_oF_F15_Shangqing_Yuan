#pragma once

#include "ofMain.h"
#include "ofxProcessFFT.h"
#include "ofxEasyFft.h"
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
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
				
    void audioIn(float * input, int bufferSize, int nChannels);
    
    void checkLookup(vector<int> &results, int a, int b, int c, int d, float res);
    
    vector<float> channel_[4];
    
    ProcessFFT FFT;
    void playsound();
    float LoudestFreq;
    
    int 	bufferCounter;
    int 	drawCounter;
    
    ofSoundStream soundStream;
    
    const static int resolutionX = 85;
    const static int resolutionY = 40;
    float lookup [resolutionX][resolutionY][4];
    
    //FFT Drawing
    ofxFloatSlider saturation;
    ofxEasyFft fft;
    ofxPanel gui;
    ofBlendMode blendMode;
    
    //Sound
    ofSoundPlayer KorgC;
    ofSoundPlayer KorgD;
    ofSoundPlayer KorgE;
    ofSoundPlayer KorgF;
    ofSoundPlayer KorgG;
    ofSoundPlayer KorgA;
    ofSoundPlayer KorgB;
    ofSoundPlayer KorgC4;
    ofSoundPlayer KorgC3;
    
    
private:
    ofVec2f posCan;
    ofVec2f posSur;
    int isRepeat = 1;
    
};
