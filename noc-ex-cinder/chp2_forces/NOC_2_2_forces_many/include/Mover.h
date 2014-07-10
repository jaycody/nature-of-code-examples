//
//  Mover.h
//  NOC_2_2_forces_many
//
//  Created by Greg Kepler on 11/13/12.
//
//

#include "cinder/app/AppBasic.h"

class Mover {
  public:
	Mover( float m, float x , float y );
	
	ci::Vec2f	mLocation, mVelocity, mAcceleration;
	float		mMass;
	
	void applyForce( ci::Vec2f force );
	void update();
	void checkEdges();
	void display();
};