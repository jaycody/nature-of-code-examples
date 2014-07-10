// Seek_Arrive
// Daniel Shiffman <http://www.shiffman.net>
// Nature of Code, Spring 2011

// Two "boids" follow the mouse position

// Implements Craig Reynold's autonomous steering behaviors
// One vehicle "seeks"
// One vehicle "arrives"
// See: http://www.red3d.com/cwr/

// C++ / openFrameworks version by
// Soixante circuits / Emmanuel Geoffray 

#include "testApp.h"
#include "Boid.h"

vector<Boid> boids;

//--------------------------------------------------------------
void testApp::setup(){
  ofSetWindowShape(640, 360);
  ofEnableSmoothing();
  ofBackground(255);

  boids.resize(100);
  for (unsigned int i = 0; i < boids.size(); i++){
    boids[i].setup();
    boids[i].setLocation(ofGetWidth()/2., ofGetHeight()/2.);
    //boids[i].setMaxSpeed(ofRandom(2, 5));
    //boids[i].setMaxForce(ofRandom(0.05, 0.1));
  }
  isDebugMode = true;
}

//--------------------------------------------------------------
void testApp::update(){
  for (unsigned int i = 0; i < boids.size(); i++){
    boids[i].flock(boids);
    boids[i].update();
    boids[i].borders();
  }
}

//--------------------------------------------------------------
void testApp::draw(){
  for (unsigned int i = 0; i < boids.size(); i++){
    boids[i].draw();
  }
  ofDrawBitmapString("Drag the mouse to generate new boids.",10,ofGetHeight()-16);
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
  Boid v;
  v.setup();
  v.setLocation(mouseX, mouseY);
  boids.push_back(v);
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
