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

Mover::Mover( float m, float x , float y, float z ):
	mMass( m ),
	mLocation( Vec3f( x, y, z ) ),
	mVelocity( Vec3f( 1.0, 0.0, 0.0 ) ),
	mAcceleration( Vec3f( 0.0, 0.0, 0.0 ) )
{
	
}

void Mover::applyForce( Vec3f force )
{
	Vec3f f = force / mMass;
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
	gl::color( Color::white() );
	gl::drawSphere( mLocation, mMass * 8 );
}