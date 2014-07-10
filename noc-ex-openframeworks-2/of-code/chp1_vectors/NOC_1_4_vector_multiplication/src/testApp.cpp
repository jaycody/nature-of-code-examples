// The Nature of Code
// Daniel Shiffman
// Draft book
//
// C++ / openFrameworks version by
// Soixante circuits / Emmanuel Geoffray 

#include "testApp.h"

// Example 1-4: Vector multiplication

//--------------------------------------------------------------
void testApp::setup(){
  ofSetWindowShape(200, 200);
  ofEnableSmoothing();
  ofBackground(255);
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
  ofVec2f mouse(mouseX, mouseY);
  ofVec2f center(ofGetWidth()/2, ofGetHeight()/2);
  mouse -= center;

  mouse *= 0.5;
  
  ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
  ofSetColor(0);
  ofLine(0, 0, mouse.x, mouse.y);
  
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
