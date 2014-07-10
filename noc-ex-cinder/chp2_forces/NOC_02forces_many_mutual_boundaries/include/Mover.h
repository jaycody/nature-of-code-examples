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
	Mover( float m, float x , float y );
	
	ci::Vec2f	mLocation, mVelocity, mAcceleration;
	float		mMass;
	
	ci::Vec2f	attract( const Mover &m );
	void		applyForce( ci::Vec2f force );
	void		update();
	void		boundaries();
	void		display();
};