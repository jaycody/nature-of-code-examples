//
//  Mover.cpp
//
//  Created by Greg Kepler on 11/28/12.
//
//

#include "cinder/app/AppBasic.h"
#include "cinder/Color.h"
#include "Mover.h"

using namespace ci;
using namespace ci::app;
using namespace std;

//static const float GRAVITY = 1.0f;		// moved gravity into mover and made it a constant

Mover::Mover( float m, float x , float y, float g ):
	mMass( m ),
	mGravity( g )
{
	mLocation = Vec2f( x, y );
	mVelocity = Vec2f( 0.0, 0.0 );
	mAcceleration = Vec2f( 0.0, 0.0 );
}

Vec2f Mover::repel( const Mover &m )
{
    Vec2f force = mLocation - m.mLocation;						// Calculate direction of force
    float d = force.length();									// Distance between objects
    d = constrain( d, 1.0f, 10000.0f );							// Limiting the distance to eliminate "extreme" results for very close or very far objects
    force.normalize();											// Normalize vector (distance doesn't matter here, we just want this vector for direction
	
    float strength = ( mGravity * mMass * m.mMass) / (d * d);	// Calculate gravitional force magnitude
    force *= ( -1 * strength );									// Get force vector --> magnitude * direction
    return force;
}

void Mover::applyForce( Vec2f force )
{
	Vec2f f = force / mMass;
	mAcceleration += f;
}

void Mover::update()
{
	mVelocity += mAcceleration;
	mLocation += mVelocity;
	mAcceleration *= 0;
}

void Mover::display()
{
	gl::color( ColorA8u::gray( 175, 200 ) );
	gl::drawSolidEllipse( mLocation, mMass, mMass );
	
	gl::color( Color::black() );
	gl::drawStrokedEllipse( mLocation, mMass, mMass );
}