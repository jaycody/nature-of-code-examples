//
//  Walker.cpp
//  Noise Walk Acceleration
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
    mNOff = Vec2f( randFloat( 1000 ), randFloat( 1000 ) );
	mHistory = list<Vec2f>();
	mReady = false;
}

// Randomly move according to floating point values
void Walker::walk()
{	
	mAcceleration.x = lmap( mPerlin.fBm( mNOff.x ), -0.5f, 0.5f, -1.0f, 1.0f );
    mAcceleration.y = lmap( mPerlin.fBm( mNOff.y ), -0.5f, 0.5f, -1.0f, 1.0f );
    mAcceleration *= 0.1;
	
    mNOff += Vec2f( 0.01, 0.01 );
	
    mVelocity += mAcceleration;
    mVelocity.limit( 1 );
    mLocation += mVelocity;
    
	
    mHistory.push_back( Vec2f(mLocation.x, mLocation.y) );
    if( mHistory.size() > 1000 ) {
		mHistory.pop_front();
    }
	
    // Stay on the screen
    mLocation.x = constrain( mLocation.x, 0.0f, (float)getWindowWidth() - 1.0f );
    mLocation.y = constrain( mLocation.y, 0.0f, (float)getWindowHeight() - 1.0f );
	
	if(!mReady) mReady = true;
}

void Walker::display()
{	
	gl::color( .68, .68, .68 );
	Rectf box = Rectf( mLocation.x-8, mLocation.y-8, mLocation.x+8, mLocation.y+8 );
	gl::drawSolidRect( box );
	gl::color( 0, 0, 0 );
	gl::drawStrokedRect( box );
	
	
	gl::begin( GL_LINE_STRIP );
    for( Vec2f v: mHistory ) {
		gl::vertex( v.x, v.y );
    };
	gl::end();
}