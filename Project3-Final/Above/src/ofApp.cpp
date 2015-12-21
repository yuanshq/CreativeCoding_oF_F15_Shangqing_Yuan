#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofToggleFullscreen();
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofSetCircleResolution(80);
    ofBackground(0 , 0, 0);
    fft.setup(pow(2.0, 12.0));
    FFT.setup();;
    
    // GUI
    gui.setup();
    gui.add(saturation.setup("Saturation", 255, 0, 255));
    gui.loadFromFile("settings.xml");
    
    // 9 output channels,
    // 4 input channels
    // 44100 samples per second
    // 2048 samples per buffer
    // 4 num buffers (latency)
    
    soundStream.listDevices();
    soundStream.setDeviceID(2);
    soundStream.getSoundStream();
    
    int bufferSize = 2048;
    int sampleRate = 44100;
    
    for(int i = 0; i < 4; i++){
        channel_[i].assign(bufferSize, 0.0);
    }
    
    bufferCounter	= 0;
    drawCounter		= 0;
    
    soundStream.setup(this, 0, 4, sampleRate, bufferSize, 8);
    soundStream.start();
    
    //Sound
    KorgC.loadSound("sounds/KorgC5.wav");
    KorgD.loadSound("sounds/KorgD5.wav");
    KorgE.loadSound("sounds/KorgE5.wav");
    KorgF.loadSound("sounds/KorgF5.wav");
    KorgG.loadSound("sounds/KorgG5.wav");
    KorgA.loadSound("sounds/KorgA5.wav");
    KorgB.loadSound("sounds/KorgB5.wav");
    KorgC3.loadSound("sounds/KorgC3.wav");
    KorgC4.loadSound("sounds/KorgC4.wav");
    
    // setup lookup table
    for (int x = 0; x < resolutionX; x++){
        for (int y = 0; y < resolutionY; y++){
            
            lookup[x][y][0] = (float)sqrt(x*x + y*y);
            lookup[x][y][1] = (float)sqrt( (resolutionX - x)*(resolutionX - x) + y*y);
            lookup[x][y][2] = (float)sqrt( (resolutionX - x)*(resolutionX - x) + (resolutionY - y)*(resolutionY - y) );
            lookup[x][y][3] = (float)sqrt( x*x + (resolutionY - y)*(resolutionY - y) );
            
            int s = 0;
            int minIdx = resolutionX*3;
            for (int i = 0; i < 4; i++){
                if (lookup[x][y][i] < minIdx){
                    minIdx = lookup[x][y][i];
                    s = i;
                }
            }
            
            float smallest = lookup[x][y][s];
            
            for (int i = 0; i < 4; i++){
                lookup[x][y][i] -= smallest;
            }
        }
    }
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    fft.update();
    FFT.update();
    ofSoundUpdate();
}


//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    
    
    int numCounted = 0;
    int count = 0;
    float amp = 0;
    int startIndex[4] = {0,0,0,0};
    
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < bufferSize; j++){
            float volume = 1;
            channel_[i][j] = input[j*4+i]* volume;
            
            if ( j > 100 && j < 2000) {
                count  = 0;
                for (int k = 5; k < 100; k+=10){
                    amp  = abs(channel_[i][j - k] * 50);
                    if (amp > 2) count++;
                }
                if (abs(channel_[i][j] * 50) > 2 && count < 1) {
                    startIndex[i] = j - 5;
                    break;
                }
            }
        }
        numCounted+=bufferSize;
    }
    
    
    /////////////////////////////update position//////////////////////////////////
    int s = 0;
    int minDur = 3000;
    
    for (unsigned i = 0; i < 4; i++){
        if (startIndex[i] < minDur){
            minDur = startIndex[i];
            s = i;
        }
    }
    
    //vector<float> relativeStart[4];
    int relativeStart[4]={0,1,2,3};
    relativeStart[s] = 0;
    
    for (unsigned i = 0; i < 4; i++){
        relativeStart[i] = startIndex[i] - startIndex[s];
    }
    
    int a = relativeStart[0];
    int b = relativeStart[1];
    int c = relativeStart[2];
    int d = relativeStart[3];
    
    vector<int> posVals;
    posVals.clear();
    
    checkLookup(posVals, a, b, c, d, resolutionX);
    ofVec2f posSufTemp = ofVec2f( (float)posVals[0], (float)posVals[1]);
    float triScaleX = (float)(ofGetWindowWidth()/(float)resolutionX);
    float triScaleY = (float)(ofGetWindowHeight()/(float)resolutionY);
    ofVec2f posCanTemp = ofVec2f( (float)posVals[0]*triScaleX + 50, (float)posVals[1]*triScaleY);
    
    ///////////////////////////update position///////////////////////////////////
    
    
    //test code, get mic number and its time
    int isOk = 0;
    for (int i = 0; i < 4; i++) {
        if(0 != startIndex[i]) {
            isOk++;
        }
    }
    
    for (int i = 0; i < 4; i++) {
        if(4 == isOk) {
            cout << i << ":" << startIndex[i] << endl;
            if(i == 3)
            {
                cout<<"posSuface value: " <<posSufTemp <<endl;
                //                cout<<"posCanTemp value: " <<posCanTemp <<endl;
                posCan = posCanTemp;
                posSur = posSufTemp;
                isRepeat = 0;
            }
        }else{
            //            posCan = ofVec2f(0, 0);
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //FFT
    vector<float> buffer;
    buffer = fft.getBins();
    
    if(posCan != ofVec2f(0,0) && posCan != ofVec2f(0,0)){
        
        ofPushMatrix();
        ofTranslate(posCan);
        ofSetLineWidth(ofGetWidth() / float(buffer.size()));
        ofEnableBlendMode(blendMode);
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < ((buffer.size())/1); i++) {
                // Hue Setting
                ofEnableAlphaBlending();
                
                float hue = ofMap(i, 0, buffer.size(), 255, 0);
                float br = ofMap(buffer[i], 0, 1, 0, 255);
                ofColor col;
                col.setHsb(hue, saturation, br);
                ofSetColor(col);
                
                // Channel1
                float Cha1 = ofMap(i, 0, buffer.size(), 0, ofGetWidth() / 2.0);
                ofLine(Cha1, -ofGetWidth() / 1.0, Cha1, ofGetWidth() / 1.0);
                ofLine(-ofGetWidth() / 1.0, Cha1, ofGetWidth() / 1.0,Cha1);
                //             Channel2
                float Cha2 = ofMap(i, 0, buffer.size(), 0, -ofGetWidth() / 2.0);
                ofLine(Cha2, -ofGetWidth() / 1.0, Cha2, ofGetWidth() / 1.0);
                ofLine( -ofGetWidth() / 1.0, Cha2, ofGetWidth() / 1.0,Cha2);
                
                
                ofDisableAlphaBlending();
                ofRotateZ(20);
            }
        }
        ofPopMatrix();
    }
    
    playsound();
    
    //GUI
    //    gui.draw();
    
    //Test code, get the position of posCan
    if (0 == isRepeat){
        cout<< "posCanvas: "<< posCan <<endl;
        isRepeat = 1;
    }
    
}

//--------------------------------------------------------------
void ofApp::playsound(){
    
    //    LoudestFreq = FFT.getLoudestFrq();
    //    cout<<"LoudestFreq: "<<LoudestFreq<<endl;
    
    //Sound
    cout<<"sound"<<endl;
    
    if(posSur.y<resolutionY*4/6){
        if (posSur.x>0 && posSur.x<resolutionX/7) {
            KorgC.play();
            KorgC.setVolume(1);
            //KorgC.setLoop(true);
            cout<<"1"<<endl;
        }else if (posSur.x>resolutionX*1/7 && posSur.x<resolutionX*2/7){
            KorgD.play();
            KorgD.setVolume(1);
            cout<<"2"<<endl;
        }else if (posSur.x>resolutionX*2/7 && posSur.x<resolutionX*3/7){
            KorgE.play();
            KorgE.setVolume(1);
            cout<<"3"<<endl;
        }else if (posSur.x>resolutionX*3/7 && posSur.x<resolutionX*4/7){
            KorgF.play();
            KorgF.setVolume(1);
            cout<<"4"<<endl;
        }else if (posSur.x>resolutionX*4/7 && posSur.x<resolutionX*5/7){
            KorgG.play();
            KorgG.setVolume(1);
            cout<<"5"<<endl;
        }else if (posSur.x>resolutionX*5/7 && posSur.x<resolutionX*6/7){
            KorgA.play();
            KorgA.setVolume(1);
            cout<<"6"<<endl;
        }else if (posSur.x>resolutionX*6/7 && posSur.x<resolutionX*7/7){
            KorgB.play();
            KorgB.setVolume(1);
            cout<<"7"<<endl;
        }
    }else if (posSur.y>resolutionY*4/6){
        if (posSur.x<resolutionX/2) {
            KorgC3.play();
            KorgC3.setVolume(1);
        }else if (posSur.x>resolutionX/2){
            KorgC4.play();
            KorgC4.setVolume(1);
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::checkLookup(vector<int> &results, int a, int b, int c, int d, float res){
    
    int outX = 0;
    int outY = 0;
    
    int count = 1;
    
    int tolerance = 5;
    
    for (int x = 0; x < resolutionX; x++){
        for (int y = 0; y < resolutionY; y++){
            
            if ( (abs(lookup[x][y][0] - a) +
                  abs(lookup[x][y][1] - b) +
                  abs(lookup[x][y][2] - c) +
                  abs(lookup[x][y][3] - d)) < 4*tolerance ){
                
                outX += x;
                outY += y;
                
                count += 1;
                
            }
        }
    }
    
    outX /= count;
    outY /= count;
    
    results.push_back(outX);
    results.push_back(outY);
    
}
//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
    
    switch (key) {
        case 49:
            blendMode = OF_BLENDMODE_ALPHA;
            break;
        case 50:
            blendMode = OF_BLENDMODE_ADD;
            break;
        case 51:
            blendMode = OF_BLENDMODE_MULTIPLY;
            break;
        case 52:
            blendMode = OF_BLENDMODE_SUBTRACT;
            break;
        case 53:
            blendMode = OF_BLENDMODE_SCREEN;
            break;
        default:
            break;
    }
    
    if( key == 's' ){
        soundStream.start();
    }
    
    if( key == 'e' ){
        soundStream.stop();
    }
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
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}