//
//  Mover.cpp
//  NOC_1_10_motion101_acceleration
//
//  Created by Greg Kepler on 11/11/12.
//
//

#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "Mover.h"

using namespace ci;
using namespace ci::app;

Mover::Mover()
{
	mLocation = Vec2f( randFloat( getWindowWidth() ), randFloat( getWindowHeight() ) );
	mVelocity = Vec2f( 0, 0 );
	mTopSpeed = 5.0;
}

// Pass the mouse position since only classes that extend AppBasic(the main class) have access to it
void Mover::update( Vec2f mousePos )
{
	// Compute a vector that points from location to mouse
    Vec2f mouse = mousePos;
    mAcceleration = mouse - mLocation;
    // Set magnitude of acceleration
    mAcceleration.normalize();
    mAcceleration *= 0.2;
    
    // Velocity changes according to acceleration
    mVelocity += mAcceleration;
    // Limit the velocity by topspeed
    mVelocity.limit( mTopSpeed );
    // Location changes by velocity
    mLocation += mVelocity;
}


void Mover::display()
{
	gl::color( 0.5, 0.5, 0.5 );
	gl::drawSolidEllipse( mLocation, 24, 24 );
	
	glLineWidth( 2.0 );
	gl::color( 0, 0, 0 );
	gl::drawStrokedEllipse( mLocation, 24, 24 );
}