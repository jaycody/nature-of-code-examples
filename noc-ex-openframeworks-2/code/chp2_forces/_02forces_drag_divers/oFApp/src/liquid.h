// The Nature of Code
// Daniel Shiffman
// Draft book
//
// C++ / openFrameworks version by
// Soixante circuits / Emmanuel Geoffray 

// Unlike mover, we are using a .h and a .cpp
// which is the more traditional way in C++

#pragma once

#include "ofMain.h"
#include "mover.h"

class liquid {

	public:
		void setup();
    void setLocation(float x, float y);
    void setWidth(float w);
    void setHeight(float h);
    void setCoeff(float c);
    bool contains(mover & m);
    ofVec2f drag(mover & m);
    void draw();
		
  private:
    ofVec2f location;
    float width;
    float height;
    float coeff;
};
