#pragma once

#include "ofMain.h"
#include "mover.h"

class attractor {

	public:
		void setup(){
      location.set(ofGetWidth()/2, ofGetHeight()/2);
      mass = 20;
    }

    ofVec2f attract(const mover & m){
      // Calculate direction of force
      ofVec2f force = location - m.getLocation();
      // Distance between objects
      float distance = force.length();
      // Limiting the distance to eliminate "extreme" results for very close or very far objects
      distance = ofClamp(distance,5.0,25.0);
      // Normalize vector (distance doesn't matter here, we just want this vector for direction)
      force.normalize();
      // Calculate gravitional force magnitude
      float G = 4;
      float strength = (G * mass * m.getMass()) / (distance * distance);
      // Get force vector --> magnitude * direction
      force *= strength;
      return force;
    }

		void draw(){
      ofSetColor(175);
      ofEllipse(location, mass * 2, mass * 2);
    }

    void setMass(float m){
      mass = m;
    }

    void setLocation( float x, float y){
      location.set(x, y);
    }
		
  private:
    ofVec2f location;
    float mass;
};
