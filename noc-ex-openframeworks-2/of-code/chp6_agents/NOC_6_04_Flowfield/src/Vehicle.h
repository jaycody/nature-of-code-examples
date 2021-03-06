#pragma once

#include "ofMain.h"
#include "FlowField.h"

class Vehicle {

  public:
    void setup(){
      location.set(30, 30);
      velocity.set(0, 0);
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

      history.push_back(location);
      if (history.size() > 100){
        history.pop_front();
      }
    }

    void applyForce(const ofVec2f & force) {
      // We could add mass here if we want A = F / M
      acceleration += force;
    }

    // Implementing Reynolds' flow field following algorithm
    // http://www.red3d.com/cwr/steer/FlowFollow.html
    void follow(const FlowField & flow) {
      // What is the vector at that spot in the flow field?
      ofVec2f desired = flow.lookup(location);
      // Scale it up by maxspeed
      desired *= maxSpeed;
      // Steering is desired minus velocity
      ofVec2f steer = desired - velocity;
      steer.limit(maxForce);  // Limit to maximum steering force
      applyForce(steer);
    }

    // Wraparound
    void borders() {
      if (location.x < -r) location.x = ofGetWidth()+r;
      if (location.y < -r) location.y = ofGetHeight()+r;
      if (location.x > ofGetWidth()+r) location.x = -r;
      if (location.y > ofGetHeight()+r) location.y = -r;
    }

    void boundaries() {
      float d = 25;

      ofVec2f desired;

      if (location.x < d) {
        desired = ofVec2f(maxSpeed, velocity.y);
      } 
      else if (location.x > ofGetWidth() -d) {
        desired = ofVec2f(-maxSpeed, velocity.y);
      } 

      if (location.y < d) {
        desired = ofVec2f(velocity.x, maxSpeed);
      } 
      else if (location.y > ofGetHeight()-d) {
        desired = ofVec2f(velocity.x, -maxSpeed);
      } 

      if (desired != 0) {
        desired.normalize();
        desired *= maxSpeed;
        ofVec2f steer = desired - velocity;
        steer.limit(maxForce);
        applyForce(steer);
      }
    }  

    // A method that calculates a steering force towards a target
    // STEER = DESIRED MINUS VELOCITY
    void arrive(const ofVec2f & target) {
      ofVec2f desired = target - location;  // A vector pointing from the location to the target
      float d = desired.length();
      // Normalize desired and scale with arbitrary damping within 100 pixels
      desired.normalize();
      if (d < 100) {
        float m = ofMap(d, 0, 100, 0, maxSpeed);
        desired *= m;
      } else {
        desired *= maxSpeed;
      }

      // Steering = Desired minus velocity
      ofVec2f steer = desired - velocity;
      steer.limit(maxForce);  // Limit to maximum steering force

      applyForce(steer);
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
      // Draw history
      /*
      ofNoFill();
      ofBeginShape();
      for (unsigned int i = 0; i < history.size(); i++){
        ofVertex(history[i].x, history[i].y);
      }
      ofEndShape();
      */

      // Draw a triangle rotated in the direction of velocity
      float theta = ofVec2f(1, 0).angle(velocity) + 90;
      ofPushMatrix();
      ofTranslate(location.x,location.y);
      ofRotate(theta);
      ofBeginShape();
      ofFill();
      ofSetColor(127);
      ofVertex(0, -r*2);
      ofVertex(-r, r*2);
      ofVertex(r, r*2);
      ofEndShape(true);
      // stroke
      ofBeginShape();
      ofNoFill();
      ofSetColor(0);
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

    void setMaxForce( float f){maxForce = f;}
    void setMaxSpeed( float s){maxSpeed = s;}

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

    deque<ofVec2f> history;
};
