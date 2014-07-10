// Seek_Arrive
// Daniel Shiffman <http://www.shiffman.net>
// Nature of Code, Spring 2011

// Two "vehicles" follow the mouse position

// Implements Craig Reynold's autonomous steering behaviors
// One vehicle "seeks"
// One vehicle "arrives"
// See: http://www.red3d.com/cwr/

// C++ / openFrameworks version by
// Soixante circuits / Emmanuel Geoffray 

#include "testApp.h"
#include "Vehicle.h"

Vehicle v;

//--------------------------------------------------------------
void testApp::setup(){
  ofSetWindowShape(800, 200);
  ofEnableSmoothing();
  ofBackground(255);
  v.setup();
  v.setLocation(ofGetWidth()/2., ofGetHeight()/2.);
}

//--------------------------------------------------------------
void testApp::update(){
  v.wander(ofVec2f(mouseX, mouseY));
  v.update();
}

//--------------------------------------------------------------
void testApp::draw(){
  ofSetHexColor(200);
  ofEllipse(mouseX, mouseY, 48, 48);
  v.draw();
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
