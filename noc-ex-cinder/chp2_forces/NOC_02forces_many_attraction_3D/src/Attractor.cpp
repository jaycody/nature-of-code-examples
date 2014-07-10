//
//  Attractor.cpp
//  A class for a draggable attractive body in our world
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

Attractor::Attractor():
	mGravity( 0.4 ),
	mMass( 20.0 ),
	mLocation( Vec3f( 0, 0, 0 ) )
{

}


Vec3f Attractor::attract( const Mover &m )
{
	Vec3f force = mLocation - m.mLocation;							// Calculate direction of force
    float d = force.length();										// Distance between objects
    d = constrain( d, 5.0f, 25.0f );								// Limiting the distance to eliminate "extreme" results for very close or very far objects
    force.normalize();												// Normalize vector (distance doesn't matter here, we just want this vector for direction)
    float strength = ( mGravity * mMass * m.mMass ) / ( d * d );	// Calculate gravitional force magnitude
    force *= strength;												// Get force vector --> magnitude * direction
    return force;
}



// Method to display
void Attractor::display()
{
	gl::color( Color::white() );
	gl::drawSphere( mLocation, mMass * 2.0, 16.0 );					// The 3rd parameter is the sphere detail/segments (defualt is 12)
}