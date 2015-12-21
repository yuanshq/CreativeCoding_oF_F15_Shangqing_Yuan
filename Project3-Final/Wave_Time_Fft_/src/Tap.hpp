//
//  Tap.hpp
//  Wave_Time_Fft_
//
//  Created by 原上青 on 12/12/15.
//
//

#include "ofMain.h"

class Tap : public ofBaseApp{
    
public:
    Tap();
    void setup(ofVec2f _pos, float _size);
    void update();
    void draw();
    
    ofVec2f pos;
    float size;
    float time;
    
    int mode;
};
