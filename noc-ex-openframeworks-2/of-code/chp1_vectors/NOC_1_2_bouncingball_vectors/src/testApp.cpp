// The Nature of Code
// Daniel Shiffman
// Draft book
//
// C++ / openFrameworks version by
// Soixante circuits / Emmanuel Geoffray 
// TODO: add accumulative drawing
// TODO: draw stroke on circle

#include "testApp.h"

// Example 1-1: Bouncing Ball, no vectors
float x = 100;
float y = 100;
float xspeed = 2.5;
float yspeed = 2;

//--------------------------------------------------------------
void testApp::setup(){
  ofSetWindowShape(200,200);
  ofEnableSmoothing();
  ofEnableAlphaBlending();
  ofBackground(255);
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
  //noStroke();
  ofFill();
  ofSetColor(255, 255, 255, 10);
  ofRect(0, 0, ofGetWidth(), ofGetHeight());
  
  // Add the current speed to the location.
  x = x + xspeed;
  y = y + yspeed;

  if ((x > ofGetWidth()) || (x < 0)) {
    xspeed = xspeed * -1;
  }
  if ((y > ofGetHeight()) || (y < 0)) {
    yspeed = yspeed * -1;
  }

  // Display circle at x location
  //stroke(0);
  ofFill();
  ofSetColor(175);
  ofEllipse(x, y, 16, 16);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
