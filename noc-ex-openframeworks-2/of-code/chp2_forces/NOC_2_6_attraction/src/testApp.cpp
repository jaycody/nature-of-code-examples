// The Nature of Code
// Daniel Shiffman
// Draft book
//
// C++ / openFrameworks version by
// Soixante circuits / Emmanuel Geoffray 

#include "testApp.h"
#include "mover.h"
#include "attractor.h"

// Example 5: attractor

mover myMover;
attractor myAttractor;

//--------------------------------------------------------------
void testApp::setup(){
  ofSetWindowShape(640, 360);
  ofEnableSmoothing();
  ofBackground(255);
  myMover.setup();
  myMover.setLocation(300, 100);
  myMover.setVelocity(1, 0);
  myAttractor.setup();
}

//--------------------------------------------------------------
void testApp::update(){
  ofVec2f force = myAttractor.attract(myMover);
  myMover.applyForce(force);
  myMover.update();

  myAttractor.drag(mouseX, mouseY);
  myAttractor.rollover(mouseX, mouseY);
}

//--------------------------------------------------------------
void testApp::draw(){
  myAttractor.draw();
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
  myAttractor.clicked(mouseX, mouseY);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
  myAttractor.stopDragging();
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
