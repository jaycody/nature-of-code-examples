//
//  Walker.cpp
//  Random Walk Noise
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
	mTx = 0.0f;
	mTy = 10000.0f;
	
	mPerlin = Perlin();
	
	// fBm returns gaussian distributed values more similar to processing's noise()
	// function than cinder's Perlin noise() function in the range of (-0.5 to 0.5).
	mX = lmap( mPerlin.fBm( mTx ), -0.5f, 0.5f, 0.0f, (float)getWindowWidth() );
	mY = lmap( mPerlin.fBm( mTy ), -0.5f, 0.5f, 0.0f, (float)getWindowHeight() );
	
	// instead of
	// mX = lmap(mPerlin.noise(mTx), 0.0f, 1.0f, 0.0f, (float)getWindowWidth());
	// mY = lmap(mPerlin.noise(mTy), 0.0f, 1.0f, 0.0f, (float)getWindowHeight());
	
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
	
	mX = lmap( mPerlin.fBm( mTx ), -0.5f, 0.5f, 0.0f, (float)getWindowWidth() );
    mY = lmap( mPerlin.fBm( mTy ), -0.5f, 0.5f, 0.0f, (float)getWindowHeight() );
	
    mTx += 0.01f;
    mTy += 0.01f;
	
	if(!mReady) mReady = true;
}