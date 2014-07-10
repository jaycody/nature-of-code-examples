//
//  Mover.cpp
//  NOC_2_1_forces
//
//  Created by Greg Kepler on 11/13/12.
//
//

#include "cinder/app/AppBasic.h"
#include "cinder/Color.h"
#include "Mover.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Mover::Mover()
{
	mLocation = Vec2f( 30.0, 30.0 );
	mVelocity = Vec2f( 0.0, 0.0 );
	mAcceleration = Vec2f( 0.0, 0.0 );
	mMass = 1.0;
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

void Mover::checkEdges()
{
	float width = getWindowWidth();
	float height = getWindowHeight();
	
	if (mLocation.x > width ) {
		mLocation.x = width;
		mVelocity.x *= -1.0;
    } else if (mLocation.x < 0.0) {
		mVelocity.x *= -1.0;
		mLocation.x = 0.0;
    }
	
    if (mLocation.y > height) {
		mVelocity.y *= -1.0;
		mLocation.y = height;
    }
}

void Mover::display()
{
	gl::color( Color::gray( 0.5 ) );
	gl::drawSolidEllipse( mLocation, 24, 24 );
	
	glLineWidth( 2.0 );
	gl::color( Color::black() );
	gl::drawStrokedEllipse( mLocation, 24, 24 );
}