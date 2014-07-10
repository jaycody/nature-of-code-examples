//
//  Mover.cpp
//
//  Created by Greg Kepler on 1/2/13.
//
//

#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "Mover.h"

using namespace ci;
using namespace ci::app;

Mover::Mover()
{
}

Mover::Mover( Vec2f loc )
{
	mLocation = loc;
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

void Mover::checkEdges() {
	
    if (mLocation.x > getWindowWidth() )
	{
		mLocation.x = 0;
    }
    else if (mLocation.x < 0)
	{
		mLocation.x = getWindowWidth();
    }
	
    if (mLocation.y > getWindowHeight() )
	{
		mLocation.y = 0;
    }
    else if (mLocation.y < 0)
	{
		mLocation.y = getWindowHeight();
    }
}

void Mover::display()
{
	float theta = atan2( mVelocity.y, mVelocity.x );	// there is no heading2d function in cinder
	
	glPushMatrix();
	gl::translate( mLocation );
	gl::rotate( toDegrees(theta) );						// cinder works with degrees instead of radians
	
	Rectf rect = Rectf( -15.0, -5.0, 15.0, 5.0 );
		
	gl::color( Color8u::gray( 127 ) );
	gl::drawSolidRect( rect );
	
	glLineWidth( 2.0 );
	gl::color( 0, 0, 0 );
	gl::drawStrokedRect( rect );
	
	glPopMatrix();
}