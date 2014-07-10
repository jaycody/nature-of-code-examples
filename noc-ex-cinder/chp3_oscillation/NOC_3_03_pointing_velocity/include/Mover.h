//
//  Mover.h
//
//  Created by Greg Kepler on 1/2/13.
//
//

#include "cinder/app/AppBasic.h"

class Mover{
  public:
	Mover();
	Mover( ci::Vec2f loc );
	void update( ci::Vec2f mousePos );
	void checkEdges();
	void display();
	
  private:
	// The Mover tracks location, velocity, and acceleration 
	ci::Vec2f	mLocation;
	ci::Vec2f	mVelocity;
	ci::Vec2f	mAcceleration;
	
	// The Mover's maximum speed
	float		mTopSpeed;
};