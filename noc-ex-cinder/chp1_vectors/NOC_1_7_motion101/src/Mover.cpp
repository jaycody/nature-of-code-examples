//
//  Mover.cpp
//  NOC_1_7_motion101
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
	mVelocity = Vec2f( randFloat( -2.0, 2.0 ), randFloat( -2.0, 2.0 ) );
}

void Mover::update()
{
	mLocation += mVelocity;
}

void Mover::checkEdges()
{
	if (mLocation.x > getWindowWidth()) {
		mLocation.x = 0;
    }
    else if (mLocation.x < 0) {
		mLocation.x = getWindowWidth();
    }
	
    if (mLocation.y > getWindowHeight()) {
		mLocation.y = 0;
    }
    else if (mLocation.y < 0) {
		mLocation.y = getWindowHeight();
    }
}

void Mover::display()
{
	gl::color( 0.5, 0.5, 0.5 );
	gl::drawSolidEllipse( mLocation, 24, 24 );
	
	glLineWidth( 2.0 );
	gl::color( 0, 0, 0 );
	gl::drawStrokedEllipse( mLocation, 24, 24 );
}