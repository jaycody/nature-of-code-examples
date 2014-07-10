//
//  Attractor.cpp
//  A class for a draggable attractive body in our world
//  NOC_2_6_attraction
//
//  Created by Greg Kepler on 11/22/12.
//
//

#include "cinder/app/AppBasic.h"
#include "cinder/CinderMath.h"
#include "Attractor.h"


using namespace ci;
using namespace ci::app;
using namespace std;

Attractor::Attractor()
{
	
}

Attractor::Attractor( Vec2f loc )
	:mDragging( false ), mRollover( false )
{
	mLocation = loc;
    mMass = 20;
    mGravity = 1;
    mDragOffset = Vec2f( 0.0, 0.0 );
}


Vec2f Attractor::attract( const Mover &m )
{
	Vec2f force = mLocation - m.mLocation;						// Calculate direction of force
    float d = force.length();									// Distance between objects
    d = constrain( d, 5.0f, 25.0f );							// Limiting the distance to eliminate "extreme" results for very close or very far objects
    force.normalize();											// Normalize vector (distance doesn't matter here, we just want this vector for direction)
    float strength = ( mGravity * mMass * m.mMass ) / ( d * d );	// Calculate gravitional force magnitude
    force *= strength;											// Get force vector --> magnitude * direction
    return force;
}



// Method to display
void Attractor::display()
{
	glLineWidth( 4.0 );
	
    if( mDragging ) gl::color( Color8u::gray( 50 ) );
    else if( mRollover ) gl::color( Color8u::gray( 100 ) );
	else gl::color( ColorA8u::gray( 175, 200 ) );
	gl::drawSolidEllipse( mLocation, mMass, mMass );
	
	gl::color( Color::black() );
	gl::drawStrokedEllipse(mLocation, mMass, mMass );
}

// The methods below are for mouse interaction
void Attractor::clicked( Vec2f mouseLoc )
{
	float d = mLocation.distance( mouseLoc );
    if( d < mMass ) {
		mDragging = true;
		mDragOffset = mLocation - mouseLoc;
    }
}

void Attractor::hover( Vec2f mouseLoc )
{
    //float d = dist(mx,my,location.x,location.y);
	float d = mLocation.distance( mouseLoc );
    if (d < mMass) {
		mRollover = true;
    }
    else {
		mRollover = false;
    }
}

void Attractor::stopDragging() {
    mDragging = false;
}



void Attractor::drag( Vec2f mouseLoc ) {
    if ( mDragging ) {
		mLocation  = mouseLoc + mDragOffset;
    }
}