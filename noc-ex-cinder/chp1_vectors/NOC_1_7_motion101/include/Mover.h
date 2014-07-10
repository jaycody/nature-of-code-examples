//
//  Mover.h
//  NOC_1_7_motion101
//
//  Created by Greg Kepler on 11/11/12.
//
//

#include "cinder/app/AppBasic.h"

class Mover{
  public:
	Mover();
	void update();
	void checkEdges();
	void display();
	
  private:
	ci::Vec2f	mLocation;
	ci::Vec2f	mVelocity;
};