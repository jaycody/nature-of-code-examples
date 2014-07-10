#pragma once

class mover {

	public:
		void setup(){
      location.set(ofGetWidth()/2, ofGetHeight()/2);
      velocity.set(0, 0);
      topSpeed = 10;
    }

		void update(){
      acceleration.set(ofRandom(-1, 1), ofRandom(-1, 1));
      acceleration.normalize();
      acceleration *= ofRandom(0, 2);

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
};
