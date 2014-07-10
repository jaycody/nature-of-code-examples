//
//  Walker.cpp
//  Random Walker
//  The Nature of Code
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "Walker.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Walker::Walker()
{
	mX = getWindowWidth() / 2;
	mY = getWindowHeight() / 2;
	mReady = false;
}

void Walker::render()
{
	if( !mReady ) return;	// to prevent drawing before update is called
	gl::color( 1, 1, 1 );
	gl::drawLine( Vec2f( mPrevX, mPrevY ), Vec2f( mX, mY ) );
}

// Randomly move according to floating point values
void Walker::step()
{
	mPrevX = mX;
	mPrevY = mY;
	
	float stepx = randFloat( 2 ) - 1;
	float stepy = randFloat( 2 ) - 1;
	
	float stepsize = montecarlo() * 50;
	stepx *= stepsize;
	stepy *= stepsize;
	
	mX += stepx;
	mY += stepy;
	mX = constrain( mX, 0.0f, (float)getWindowWidth() - 1 );
    mY = constrain( mY, 0.0f, (float)getWindowHeight() - 1 );
	
	if( !mReady ) mReady = true;
}

float Walker::montecarlo()
{
	while(true)
	{
		float r1 = randFloat() * 1;
		float probability = pow( 1.0 - r1, 8 );
		
		float r2 = randFloat() * 1;
		if( r2 < probability ) {
			return r1;
		}
	}
}