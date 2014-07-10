#pragma once

#include "ofMain.h"

class mover {

	public:
		void setup(){
      location.set(30, 30);
      velocity.set(0, 0);
      acceleration.set(0, 0);
      mass = 1;
      G = 0.4;
    }

		void applyForce(const ofVec2f & force){
      ofVec2f f(force/mass);
      acceleration += f;
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
      float strength = (G * mass * m.getMass()) / (distance * distance);
      // Get force vector --> magnitude * direction
      force *= strength;
      return force;
    }

		void update(){
      velocity += acceleration;
      location += velocity;
      acceleration *= 0;
    }

		void draw(){
      ofSetColor(175);
      ofEllipse(location, mass * 16, mass * 16);
    }

    float getMass() const{
      return mass;
    }

    void setMass(float m){
      mass = m;
    }

    void setLocation( float x, float y){
      location.set(x, y);
    }

    void setVelocity( float x, float y){
      velocity.set(x, y);
    }

    const ofVec2f& getLocation() const{
      return location;
    }

    const ofVec2f& getVelocity() const{
      return velocity;
    }

    void boundaries(){
      float d = 50;

      ofVec2f force(0, 0);

      if (location.x > ofGetWidth() - d){
        force.x = -1;
      } else if (location.x < d){
        force.x = 1;
      }
      
      if (location.y > ofGetHeight() - d){
        force.y = -1;
      } else if (location.y < d){
        force.y = 1;
      }

      force.normalize();
      force *= 0.1;
      applyForce(force);

    }
		
  private:
    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    float mass;
    float G;
};
