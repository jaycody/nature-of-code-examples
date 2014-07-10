//
//  Attractor.h
//  NOC_2_6_attraction
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
	Attractor( ci::Vec2f loc );
	ci::Vec2f attract( const Mover &m );
	void display();
	void clicked( ci::Vec2f mouseLoc );
	void hover( ci::Vec2f mouseLoc );
	void stopDragging();
	void drag( ci::Vec2f mouseLoc );
	
	float		mMass;			// Mass, tied to size
	float		mGravity;		// Gravitational Constant
	ci::Vec2f	mLocation;		// Location
	bool		mDragging;		// Is the object being dragged?
	bool		mRollover;		// Is the mouse over the ellipse?
	ci::Vec2f	mDragOffset;	// holds the offset for when object is clicked on
};