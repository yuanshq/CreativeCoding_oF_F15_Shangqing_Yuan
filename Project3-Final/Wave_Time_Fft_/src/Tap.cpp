//
//  Tap.cpp
//  Wave_Time_Fft_
//
//  Created by 原上青 on 12/12/15.
//
//

#include "Tap.hpp"

void Tap::setup(ofVec2f _pos, float _size){
    
    pos = _pos;
    size = _size;
    
    time = 0.0f;
    mode = 0;
}

void Tap::update(){
    
}

void Tap::draw(){
    
    if(mode == 0 ){
        ofSetColor(1.0f, 1.0f, 1.0f, 1.0f-time);
    }else{
        ofSetColor(1.0f, 0.0f, 0.0f);
    }
    
    
    ofSetLineWidth(size*0.25f - size*0.25f*time);
    ofCircle(pos, 10 + size*time);
    
    time += 0.01f;
    
    ofSetLineWidth(1);
}