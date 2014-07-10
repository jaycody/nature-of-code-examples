#pragma once

#include "ofMain.h"

class Vehicle {

  public:
    void setup(){
      location.set(30, 30);
      velocity.set(0, -2);
      acceleration.set(0, 0);
      r = 6;
      maxSpeed = 4;
      maxForce = 0.1;
    }

    // Method to update location
    void update(){
      // Update velocity
      velocity += acceleration;
      // Limit speed
      velocity.limit(maxSpeed);
      location += velocity;
      // Reset acceleration to 0 each cycle
      acceleration *= 0;
    }

    void applyForce(const ofVec2f & force) {
      // We could add mass here if we want A = F / M
      acceleration += force;
    }

    // A method that calculates a steering force towards a target
    // STEER = DESIRED MINUS VELOCITY
    void seek(const ofVec2f & target) {
      ofVec2f desired = target - location;  // A vector pointing from the location to the target

      // Normalize desired and scale to maximum speed
      desired.normalize();
      desired *= maxSpeed;
      // Steering = Desired minus velocity
      ofVec2f steer = desired - velocity;
      steer.limit(maxForce);  // Limit to maximum steering force

      applyForce(steer);
    }

    void draw(){
      // Draw a triangle rotated in the direction of velocity
      float theta = ofVec2f(1, 0).angle(velocity) + 90;
      ofFill();
      ofSetColor(127);
      ofPushMatrix();
      ofTranslate(location.x,location.y);
      ofRotate(theta);
      ofBeginShape();
      ofVertex(0, -r*2);
      ofVertex(-r, r*2);
      ofVertex(r, r*2);
      ofEndShape(true);
      ofPopMatrix();
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

  private:
    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    float r;
    float maxForce;
    float maxSpeed;
};
