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
	mX = getWindowWidth()/2;
	mY = getWindowHeight()/2;
	
	mReady = false;
}

void Walker::render()
{
	if( !mReady ) return;	// to prevent drawing before update is called
	gl::color( 1, 1, 1 );
	
	// drawing a 1 pixel circle or a line that is 1 pixel wide is the
	// closest thing to drawing a point in processing
	//gl::drawSolidCircle(Vec2f(mX, mY), 1);
	gl::drawLine( Vec2i( mX, mY ), Vec2i( mX + 1, mY ) );
}

// Randomly move according to floating point values
void Walker::step()
{
	int stepX = randInt( 3 ) - 1;
	int stepY = randInt( 3 ) - 1;
	
	mX += stepX;
    mY += stepY;
	
    mX = constrain( mX, 0, getWindowWidth() - 1 );
	mY = constrain( mY, 0, getWindowHeight() - 1 );
	
	if(!mReady) mReady = true;
}