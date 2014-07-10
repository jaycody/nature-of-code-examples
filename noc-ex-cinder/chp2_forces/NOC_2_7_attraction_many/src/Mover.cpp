//
//  Mover.cpp
//  NOC_2_7_attraction_many
//
//  Created by Greg Kepler on 11/13/12.
//
//

#include "cinder/app/AppBasic.h"
#include "cinder/Color.h"
#include "cinder/Rand.h"
#include "Mover.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Mover::Mover( float m, float x , float y ):
	mAngle( 0 ), mAAcceleration( 0 ), mAVelocity( 0 )
{
	mMass = m;
	mLocation = Vec2f( x, y );
	mVelocity = Vec2f( randFloat( -1.0, 1.0 ), randFloat( -1.0, 1.0 ) );
	mAcceleration = Vec2f( 0.0, 0.0 );
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
	
	mAAcceleration = mAcceleration.x / 10.0;
	mAVelocity += mAAcceleration;
	mAVelocity = constrain( mAVelocity, -0.1f, 0.1f );
	mAngle += mAVelocity;
	
	mAcceleration *= 0;
}

void Mover::display()
{
	float w = mMass * 16;
	Rectf drawRect = Rectf( -w/2, -w/2, w/2, w/2 );
	
	glPushMatrix();
	gl::translate( mLocation );
	gl::rotate( toDegrees( mAngle ) );
	
	gl::color( ColorA8u::gray( 175, 200 ) );
	gl::drawSolidRect( drawRect );
	
	gl::color( Color::black() );
	gl::drawStrokedRect( drawRect );
	glPopMatrix();
}