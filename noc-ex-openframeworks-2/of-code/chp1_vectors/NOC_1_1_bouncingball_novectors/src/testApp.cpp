// The Nature of Code
// Daniel Shiffman
// Draft book
//
// C++ / openFrameworks version by
// Soixante circuits / Emmanuel Geoffray 
// TODO: add accumulative drawing
// TODO: draw stroke on circle

#include "testApp.h"

// Example 1-2: Bouncing Ball, with PVector!
ofVec2f location;
ofVec2f velocity;

//--------------------------------------------------------------
void testApp::setup(){
  ofSetWindowShape(200,200);
  ofEnableSmoothing();
  ofEnableAlphaBlending();
  ofBackground(255);
  location.set(100,100);
  velocity.set(2.5,5);
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
  location += velocity;

  if ((location.x > ofGetWidth()) || (location.x < 0)) {
    velocity.x = velocity.x * -1;
  }
  if ((location.y > ofGetHeight()) || (location.y < 0)) {
    velocity.y = velocity.y * -1;
  }

  // Display circle at x location
  //stroke(0);
  ofFill();
  ofSetColor(175);
  ofEllipse(location.x, location.y, 16, 16);
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
