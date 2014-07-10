//
//  Walker.cpp
//  The Nature of Code
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "cinder/CinderMath.h"
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
	
	// drawing a 1 pixel circle or a line that is 1 pixel wide is the
	// closest thing to drawing a point in processing
	//gl::drawSolidCircle(Vec2f(mX, mY), 1);
	gl::drawLine(Vec2f(mX, mY), Vec2f(mX+1, mY));
}

// Randomly move according to floating point values
void Walker::step()
{
	float stepX = randFloat( -1.0f, 1.0f );
	float stepY = randFloat( -1.0f, 1.0f );
	
	mX += stepX;
    mY += stepY;
	
    mX = constrain( mX, 0.0f, (float)getWindowWidth() - 1 );
	mY = constrain( mY, 0.0f, (float)getWindowHeight() - 1 );
	
	if(!mReady) mReady = true;
}