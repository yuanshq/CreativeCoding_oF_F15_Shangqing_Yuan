//
//  leaf.h
//  Leaf
//
//  Created by 原上青 on 9/10/15.
//
//

#ifndef __leaves__leaf__
#define __leaves__leaf__


#include "ofMain.h"

class leaf {
    
public:
    void setup();
    void update();
    void draw();
    
private:
    
    float xPos, yPos;
    float stemLength, stemWidth;
    float leafLength, leafWidth;
    ofColor stemColor;
    ofColor leafColor;
    
    float scaleFactor;
    float rotation;
    
    float leafCurvature; //?
    
};


#endif /* defined(__leaves__leaf__) */
