// The Nature of Code
// Daniel Shiffman
// Draft book
//
// C++ / openFrameworks version by
// Soixante circuits / Emmanuel Geoffray 
// TODO: add accumulative drawing
// TODO: draw stroke on circle

#include "testApp.h"

// Example 3-2: angular motion

float angle = 0;
float aVelocity = 0;
float aAcceleration = 0.005;

//--------------------------------------------------------------
void testApp::setup(){
  ofSetWindowShape(640, 360);
  ofEnableSmoothing();
  ofEnableAlphaBlending();
  ofBackground(255);
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
  ofFill();
  ofSetColor(175);
  ofSetRectMode(OF_RECTMODE_CENTER);
  ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
  ofRotate(angle);
  ofLine(-150, 0, 150, 0);
  ofEllipse(150, 0, 8, 8);
  ofEllipse(-150, 0, 8, 8);

  // in oF, angles are in degrees
  angle += aVelocity;
  aVelocity += aAcceleration;
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
