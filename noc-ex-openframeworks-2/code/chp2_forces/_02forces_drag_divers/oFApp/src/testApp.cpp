// The Nature of Code
// Daniel Shiffman
// Draft book
//
// C++ / openFrameworks version by
// Soixante circuits / Emmanuel Geoffray 

#include "testApp.h"
#include "mover.h"
#include "liquid.h"

// Example 5: fluids

vector<mover> movers;
liquid myliquid;

//--------------------------------------------------------------
void testApp::setup(){
  ofSetWindowShape(640, 360);
  ofEnableSmoothing();
  ofBackground(255);

  movers.resize(5);
  reset();

  myliquid.setup();
  myliquid.setLocation(0, ofGetHeight()/2.);
  myliquid.setWidth(ofGetWidth());
  myliquid.setHeight(ofGetHeight()/2.);
  myliquid.setCoeff(0.1);

}

//--------------------------------------------------------------
void testApp::reset(){
  for (unsigned int i = 0; i < movers.size(); i++){
    movers[i].setup();
    movers[i].setMass(ofRandom(1, 5));
    movers[i].setLocation(30 + (i * 70), 0);
  }
}
//--------------------------------------------------------------
void testApp::update(){
  ofVec2f wind(0.001, 0);
  ofVec2f gravity(0, 0.1);
  for (unsigned int i = 0; i < movers.size(); i++){
    //fluids
    if (myliquid.contains(movers[i])){
      ofVec2f drag = myliquid.drag(movers[i]);
      movers[i].applyForce(drag);
    }

    movers[i].applyForce(wind);
    movers[i].applyForce(gravity);
    movers[i].update();
    movers[i].checkEdges();
  }
}

//--------------------------------------------------------------
void testApp::draw(){
  myliquid.draw();
  for (unsigned int i = 0; i < movers.size(); i++){
    movers[i].draw();
  }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
  reset();
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
  reset();
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
