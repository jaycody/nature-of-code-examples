#pragma once

#include "ofMain.h"

class mover {

	public:
		void setup(){
      location.set(30, 30);
      velocity.set(0, 0);
      acceleration.set(0, 0);
      mass = 1;
      angle = 0;
      aVelocity = 0;
      aAcceleration = 0;
    }

		void applyForce(const ofVec2f & force){
      ofVec2f f(force/mass);
      acceleration += f;
    }

		void update(){
      velocity += acceleration;
      location += velocity;

      aAcceleration = acceleration.x * 5;
      aVelocity += aAcceleration;
      aVelocity = ofClamp(aVelocity, -5, 5);
      angle += aVelocity;

      acceleration *= 0;
    }

		void draw(){
      ofSetColor(175);
      ofSetRectMode(OF_RECTMODE_CORNER);
      ofPushMatrix();
        ofTranslate(location.x,location.y);
        ofRotate(angle);
        ofRect(0,0,mass*16,mass*16);
      ofPopMatrix();
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
    float mass;

    float angle;
    float aVelocity;
    float aAcceleration;
};
