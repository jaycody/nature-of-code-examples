//
//  Mover.h
//
//  Created by Greg Kepler on 11/28/12.
//
//

#pragma once

#include "cinder/app/AppBasic.h"

class Mover {
public:
	Mover( float m, float x , float y, float g );
	
	ci::Vec3f	mLocation, mVelocity, mAcceleration;
	float		mMass, mGravity;
	
	void		applyForce( ci::Vec3f force );
	void		update();
	void		display();
};