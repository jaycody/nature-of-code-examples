#pragma once

class mover {

	public:
		void setup(){
      location.set(ofGetWidth()/2, ofGetHeight()/2);
      velocity.set(0, 0);
      topSpeed = 4;
      xoff = 1000;
      yoff = 0;
    }

		void update(){
      float ax = ofMap(ofNoise(xoff), 0, 1, -1, 1);
      float ay = ofMap(ofNoise(yoff), 0, 1, -1, 1);
      acceleration.set(ax, ay);
      xoff += 0.01;
      yoff += 0.01;

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

    float xoff;
    float yoff;
};
