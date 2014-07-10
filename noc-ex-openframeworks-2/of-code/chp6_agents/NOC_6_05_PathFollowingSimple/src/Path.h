#pragma once

#include "ofMain.h"

class Path {
  private:
    // A Path is line between two points (ofVec2f objects)
    ofVec2f start;
    ofVec2f end;
    // A path has a radius, i.e how far is it ok for the boid to wander off
    float radius;

  public:
    void setup() {
      // Arbitrary radius of 20
      radius = 20;
      start.set(0,ofGetHeight()/3);
      end.set(ofGetWidth(),2*ofGetHeight()/3);
    }

    // Draw the path
    void draw() {
      ofBeginShape();
      ofFill();
      ofSetColor(100);
      ofVertex(start.x, start.y-radius);
      ofVertex(start.x, start.y+radius);
      ofVertex(end.x, end.y+radius);
      ofVertex(end.x, end.y-radius);
      ofEndShape(true);

      ofSetColor(0);
      ofLine(start.x,start.y,end.x,end.y);
    }

    ofVec2f getStart() const { return start;}
    ofVec2f getEnd() const { return end;}
    float getRadius() const {return radius;}
};
