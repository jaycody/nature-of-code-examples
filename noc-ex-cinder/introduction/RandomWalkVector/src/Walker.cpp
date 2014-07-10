//
//  Walker.cpp
//  Random Walker Vectors
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
	mLoc = Vec2f( getWindowWidth() / 2, getWindowHeight() / 2 );
}

// Randomly move up, down, left, right, or stay in one place
void Walker::walk()
{
	Vec2f vel = randVec2f() * Vec2f( 2.0f, 2.0f );
	mLoc += vel;
    
	// Stay on the screen
    mLoc.x = constrain( mLoc.x, 0.0f, (float)getWindowWidth() - 1 );
    mLoc.y = constrain( mLoc.y, 0.0f, (float)getWindowHeight() - 1 );
}

void Walker::render()
{
	gl::color( .68, .68, .68 );
	Rectf box = Rectf( mLoc.x - 20, mLoc.y - 20, mLoc.x + 20, mLoc.y + 20 );
	gl::drawSolidRect( box );
	gl::color( 0, 0, 0 );
	gl::drawStrokedRect( box );
}
