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

vector<mover> movers;
attractor myAttractor;

//--------------------------------------------------------------
void testApp::setup(){
  ofSetWindowShape(640, 360);
  ofEnableSmoothing();
  ofBackground(255);
  movers.resize(10);
  for (unsigned int i = 0; i < movers.size(); i++){
    movers[i].setup();
    movers[i].setLocation(ofRandomWidth(), ofRandomHeight());
    movers[i].setMass(ofRandom(0.1, 2));
  }
  myAttractor.setup();
}

//--------------------------------------------------------------
void testApp::update(){
  for (unsigned int i = 0; i < movers.size(); i++){
    ofVec2f force = myAttractor.attract(movers[i]);
    movers[i].applyForce(force);
    movers[i].update();
  }

  myAttractor.drag(mouseX, mouseY);
  myAttractor.rollover(mouseX, mouseY);
}

//--------------------------------------------------------------
void testApp::draw(){
  myAttractor.draw();
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
