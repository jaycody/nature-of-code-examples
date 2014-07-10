#pragma once

class mover {

	public:
		void setup(){
      location.set(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()));
      velocity.set(ofRandom(-2, 2), ofRandom(-2, 2));
    }

		void update(){
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
};
