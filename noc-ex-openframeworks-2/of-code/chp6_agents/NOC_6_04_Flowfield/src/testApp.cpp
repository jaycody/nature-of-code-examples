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
#include "FlowField.h"

FlowField flowfield;
vector<Vehicle> vehicles;

//--------------------------------------------------------------
void testApp::setup(){
  ofSetWindowShape(640, 360);
  ofEnableSmoothing();
  ofBackground(255);
  flowfield.setup(16);
  vehicles.resize(120);
  for (unsigned int i = 0; i < vehicles.size(); i++){
    vehicles[i].setup();
    vehicles[i].setLocation(ofRandomWidth(), ofRandomHeight());
    vehicles[i].setMaxSpeed(ofRandom(2, 5));
    vehicles[i].setMaxForce(ofRandom(0.1, 0.5));
  }
}

//--------------------------------------------------------------
void testApp::update(){
  for (unsigned int i = 0; i < vehicles.size(); i++){
    vehicles[i].follow(flowfield);
    vehicles[i].update();
    vehicles[i].borders();
  }
}

//--------------------------------------------------------------
void testApp::draw(){
  if (isDebugMode){
    flowfield.draw();
  }
  for (unsigned int i = 0; i < vehicles.size(); i++){
    vehicles[i].draw();
  }
  //ofText("Hit space bar to toggle debugging lines.\nClick the mouse to generate a new flow field.",10,height-30);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
  if (key == ' ') {
    isDebugMode = !isDebugMode;
  }
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
  flowfield.init();
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
