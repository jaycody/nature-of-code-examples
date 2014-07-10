//
//  Mover.h
//  NOC_1_10_motion101_acceleration
//
//  Created by Greg Kepler on 11/11/12.
//
//

#include "cinder/app/AppBasic.h"

class Mover{
  public:
	Mover();
	void update( ci::Vec2f mousePos );
	void display();
	
  private:
	// The Mover tracks location, velocity, and acceleration 
	ci::Vec2f	mLocation;
	ci::Vec2f	mVelocity;
	ci::Vec2f	mAcceleration;
	
	// The Mover's maximum speed
	float		mTopSpeed;
};