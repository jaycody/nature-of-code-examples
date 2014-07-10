//
//  Mover.h
//  NOC_1_9_motion101_acceleration
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
	ci::Vec2f	mAcceleration;
	float		mTopSpeed;
};