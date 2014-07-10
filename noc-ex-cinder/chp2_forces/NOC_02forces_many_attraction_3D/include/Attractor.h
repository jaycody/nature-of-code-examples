//
//  Attractor.h
//
//  Created by Greg Kepler on 11/22/12.
//
//

#pragma once

#include "cinder/app/AppBasic.h"
#include "Mover.h"

class Attractor {
public:
	Attractor();
	ci::Vec3f attract( const Mover &m );
	void display();
	
	float		mMass;			// Mass, tied to size
	float		mGravity;		// Gravitational Constant
	ci::Vec3f	mLocation;		// Location
};