//
//  leaf.h
//  Leaf
//
//  Created by 原上青 on 9/10/15.
//
//

#ifndef __Leaf__leaf__
#define __Leaf__leaf__


#include <stdio.h>

class leaf : public ofBaseApp{
    
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


#endif /* defined(__Leaf__leaf__) */
