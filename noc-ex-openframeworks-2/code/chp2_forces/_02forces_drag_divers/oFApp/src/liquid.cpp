// The Nature of Code

// Draft book
//
// C++ / openFrameworks version by
// Soixante circuits / Emmanuel Geoffray 

// Unlike mover, we are using a .h and a .cpp
// which is the more traditional way in C++

#include "liquid.h"

//--------------------------------------------------------------
void liquid::setup(){
  location.set(0, 0);
  width = 0;
  height = 0;
  coeff = 0.01;
}

//--------------------------------------------------------------
bool liquid::contains(mover & m){
  ofVec2f l = m.getLocation();
  if (l.x > location.x && l.x < location.x + width 
    && l.y > location.y && l.y < location.y + height) {
    return true;
  }  
  else {
    return false;
  }
}

//--------------------------------------------------------------
ofVec2f liquid::drag(mover & m){
    float speed = m.getVelocity().length();
    float dragMagnitude = -1 * coeff * speed * speed;

    ofVec2f drag = m.getVelocity();
    drag.normalize();
    drag *= dragMagnitude;
    
    return drag;
}

//--------------------------------------------------------------
void liquid::draw(){
  ofSetColor(175, 175, 255);
  ofRect(location, width, height);
}

//--------------------------------------------------------------
void liquid::setLocation(float x, float y){
  location.set(x, y);
}

//--------------------------------------------------------------
void liquid::setWidth(float w){
  width = w;
}

//--------------------------------------------------------------
void liquid::setHeight(float h){
  height = h;
}

//--------------------------------------------------------------
void liquid::setCoeff(float c){
  coeff = c;
}

