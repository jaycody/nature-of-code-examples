//
//  Mover.h
//  NOC_2_1_forces
//
//  Created by Greg Kepler on 11/13/12.
//
//

#include "cinder/app/AppBasic.h"

class Mover {
  public:
	Mover();
	
	ci::Vec2f	mLocation, mVelocity, mAcceleration;
	float		mMass;
	
	void applyForce( ci::Vec2f force );
	void update();
	void checkEdges();
	void display();
};