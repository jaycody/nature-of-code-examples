#pragma once

#include "ofMain.h"

class mover {

	public:
		void setup(){
      location.set(ofRandomWidth(), ofRandomHeight());
      velocity.set(0, 0);
      acceleration.set(0, 0);
      topSpeed = 6;
    }

		void applyForce(const ofVec2f & f){
      acceleration = f;
    }

		void update(){
      velocity += acceleration;
      velocity.limit(topSpeed);
      location += velocity;
    }

		void draw(){
      ofSetColor(175);
      ofEllipse(location, 16, 16);
    }

    void checkEdges(){

      if (location.x > ofGetWidth()){
        velocity.x *= -1;
        location.x = ofGetWidth();
      } else if (location.x < 0){
        velocity.x *= -1;
        location.x = 0;
      }
      
      if (location.y > ofGetHeight()){
        velocity.y *= -1;
        location.y = ofGetHeight();
      } else if (location.y < 0){
        velocity.y *= -1;
        location.y = 0;
      }

    }
		
  private:
    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    float topSpeed;
};
