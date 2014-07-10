// The Nature of Code
// Daniel Shiffman
// Draft book
//
// C++ / openFrameworks version by
// Soixante circuits / Emmanuel Geoffray 

#include "testApp.h"
#include "mover.h"

// Example 2-c: Motion 101 acceleration perlin

mover myMover;

//--------------------------------------------------------------
void testApp::setup(){
  ofSetWindowShape(640, 360);
  ofEnableSmoothing();
  ofBackground(255);
  myMover.setup();
}

//--------------------------------------------------------------
void testApp::update(){
  myMover.update();
  myMover.checkEdges();
}

//--------------------------------------------------------------
void testApp::draw(){
 myMover.draw(); 
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
