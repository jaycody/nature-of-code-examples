// The Nature of Code
// Daniel Shiffman
// Draft book
//
// C++ / openFrameworks version by
// Soixante circuits / Emmanuel Geoffray 

#include "testApp.h"
#include "mover.h"

// Example 2-d: Motion 101 acceleration array

vector<mover> movers;

//--------------------------------------------------------------
void testApp::setup(){
  ofSetWindowShape(640, 360);
  ofEnableSmoothing();
  ofBackground(255);
  movers.resize(20);
  for (unsigned int i = 0; i < movers.size(); i++){
    movers[i].setup();
  }
}

//--------------------------------------------------------------
void testApp::update(){
  for (unsigned int i = 0; i < movers.size(); i++){
    movers[i].update();
    movers[i].checkEdges();
  }
}

//--------------------------------------------------------------
void testApp::draw(){
  for (unsigned int i = 0; i < movers.size(); i++){
    movers[i].draw();
  }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
  ofVec2f mouse(x, y);
  for (unsigned int i = 0; i < movers.size(); i++){
    movers[i].setTarget(mouse);
  }
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
