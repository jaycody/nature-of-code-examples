//
//  Walker.cpp
//  I.5 Noise Walk
//  The Nature of Code
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "cinder/CinderMath.h"
#include "cinder/Perlin.h"
#include "Walker.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Walker::Walker()
{
	mPerlin = Perlin();
	
	mLocation = Vec2f( (float)getWindowWidth() / 2, (float)getWindowHeight() / 2 );
    mNOff = Vec2f ( randFloat( 1000 ), randFloat( 1000 ) );
	
	mReady = false;
}

// Randomly move according to floating point values
void Walker::walk()
{
	mLocation.x = lmap( mPerlin.fBm(mNOff.x), -0.5f, 0.5f, 0.0f, (float) getWindowWidth() );
	mLocation.y = lmap( mPerlin.fBm(mNOff.y), -0.5f, 0.5f, 0.0f, (float) getWindowHeight() );
	
	mNOff += Vec2f( 0.01, 0.01 );
	
	if(!mReady) mReady = true;
}

void Walker::display()
{
	if(!mReady) return;	// to prevent drawing before update is called
	gl::color( 1, 1, 1 );
	
	gl::color( 0.5, 0.5, 0.5 );
	gl::drawSolidEllipse( mLocation, 24, 24);
	
	glLineWidth( 2.0f );
	gl::color( 0, 0, 0 );
	gl::drawStrokedEllipse( mLocation, 24, 24);
}