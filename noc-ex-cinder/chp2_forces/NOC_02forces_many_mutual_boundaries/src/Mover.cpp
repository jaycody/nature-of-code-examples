
//
//  Mover.cpp
//
//  Created by Greg Kepler on 12/1/12.
//
//

#include "cinder/app/AppBasic.h"
#include "cinder/Color.h"
#include "Mover.h"

using namespace ci;
using namespace ci::app;
using namespace std;

static const float GRAVITY = 0.4f;		// moved gravity into mover and made it a constant

Mover::Mover( float m, float x , float y )
{
	mMass = m;
	mLocation = Vec2f( x, y );
	mVelocity = Vec2f( 0.0, 0.0 );
	mAcceleration = Vec2f( 0.0, 0.0 );
}

Vec2f Mover::attract( const Mover &m )
{
	Vec2f force = mLocation - m.mLocation;						// Calculate direction of force
    float d = force.length();									// Distance between objects
    d = constrain( d, 5.0f, 25.0f );							// Limiting the distance to eliminate "extreme" results for very close or very far objects
    force.normalize();											// Normalize vector (distance doesn't matter here, we just want this vector for direction)
    float strength = ( GRAVITY * mMass * m.mMass ) / ( d * d );	// Calculate gravitional force magnitude
    force *= strength;											// Get force vector --> magnitude * direction
    return force;
}

void Mover::applyForce( Vec2f force )
{
	Vec2f f = force / mMass;
	mAcceleration += f;
}

void Mover::boundaries() {
	
    float d = 50;
	
    Vec2f force = Vec2f( 0, 0 );
	
    if( mLocation.x < d ) {
		force.x = 1;
    }
    else if( mLocation.x > getWindowWidth() - d ) {
		force.x = -1;
    }
	
    if( mLocation.y < d ) {
		force.y = 1;
    }
    else if( mLocation.y > getWindowHeight() - d ) {
		force.y = -1;
    }
	
    
    if( force != Vec2f::zero() ){
		force.normalize();
		force *= 0.1;
	}
	
    applyForce(force);
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
	gl::drawSolidEllipse( mLocation, mMass * 8, mMass * 8 );
	
	gl::color( Color::black() );
	gl::drawStrokedEllipse( mLocation, mMass * 8, mMass * 8 );
}