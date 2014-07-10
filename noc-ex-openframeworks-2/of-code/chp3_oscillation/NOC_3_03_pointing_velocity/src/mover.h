#pragma once

#include "ofMain.h"

class mover {

	public:
		void setup(){
      location.set(ofGetWidth()/2, ofGetHeight()/2);
      velocity.set(0, 0);
      topSpeed = 4;
    }

		void setTarget(const ofVec2f & t){
      acceleration = t - location;
      acceleration.normalize();
      acceleration *= 0.5;
    }

		void update(){
      // acceleration towards the mouse is set in testApp::mouseMoved
      velocity += acceleration;
      velocity.limit(topSpeed);
      location += velocity;
    }

		void draw(){
      //float theta = atan2(velocity.y, velocity.x) * 180. / PI;
      // same as
      float theta = ofVec2f(1, 0).angle(velocity);
      ofSetColor(175);
      ofSetRectMode(OF_RECTMODE_CENTER);
      ofPushMatrix();
        ofTranslate(location.x,location.y);
        ofRotate(theta);
        ofRect(0,0,30,10);
      ofPopMatrix();
    }

    void checkEdges(){

      if (location.x > ofGetWidth()){
        location.x = 0;
      } else if (location.x < 0){
        location.x = ofGetWidth();
      }
      
      if (location.y > ofGetHeight()){
        location.y = 0;
      } else if (location.y < 0){
        location.y = ofGetHeight();
      }

    }
		
  private:
    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    float topSpeed;
};
