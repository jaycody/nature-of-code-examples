//
//  Attractor.h
//
//  Created by Greg Kepler on 1/1/13.
//

#pragma once

#include "cinder/app/AppBasic.h"
#include "Mover.h"

class Attractor {
public:
	Attractor();
	Attractor( ci::Vec2f loc );
	ci::Vec2f attract( const Mover &m );
	void display();
	
	float		mMass;			// Mass, tied to size
	float		mGravity;		// Gravitational Constant
	ci::Vec2f	mLocation;		// Location
};