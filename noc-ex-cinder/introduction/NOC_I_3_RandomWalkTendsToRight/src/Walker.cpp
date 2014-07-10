//
//  Walker.cpp
//  I.3 Random Walker Tends to Right
//  The Nature of Code
//
//  Created by Greg Kepler
//

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "cinder/CinderMath.h"
#include "Walker.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Walker::Walker()
{
	mX = getWindowWidth() / 2;
	mY = getWindowHeight() / 2;
}

// Randomly move up, down, left, right, or stay in one place
void Walker::step()
{
	float r = randFloat(1);
    
    if (r < 0.4) {
		mX++;
    } else if (r < 0.6) {
		mX--;
    } else if (r < 0.8) {
		mY++;
    } else {
		mY--;
    }
	
    mX = constrain( mX, 0.0f, (float)getWindowWidth() - 1.0f );
    mY = constrain( mY, 0.0f, (float)getWindowHeight() - 1.0f );
}

void Walker::render()
{
	gl::color( 0, 0, 0 );
	glLineWidth( 2.0 );
	gl::drawLine( Vec2f( mX, mY ), Vec2f( mX+1, mY ) );
}
