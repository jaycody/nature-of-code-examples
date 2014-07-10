//
//  Attractor.cpp
//
//  Created by Greg Kepler on 12/22/12.
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
{
	mLocation = loc;
    mMass = 20;
    mGravity = 0.4f;
}


Vec2f Attractor::attract( const Mover &m )
{
	Vec2f force = mLocation - m.mLocation;							// Calculate direction of force
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
	gl::color( Color8u::gray( 127 ) );
	gl::drawSolidEllipse( mLocation, 24, 24 );
	
	glLineWidth( 2.0 );
	gl::color( Color::black() );
	gl::drawStrokedEllipse(mLocation, 24, 24 );
}