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
	
	ci::Vec2f	mLocation, mVelocity, mAcceleration;
	float		mMass, mGravity;
	
	ci::Vec2f	repel( const Mover &m );
	void		applyForce( ci::Vec2f force );
	void		update();
	void		display();
};