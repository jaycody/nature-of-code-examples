//
//  Walker.cpp
//  Random Walker (No Vectors)
//  The Nature of Code
//
//  Created by Greg Kepler
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
}

// Randomly move up, down, left, right, or stay in one place
void Walker::walk()
{
	float vx = randFloat( 4 ) - 2;
    float vy = randFloat( 4 ) - 2;
    mX += vx;
    mY += vy;
	
	// Stay on the screen
    mX = constrain( mX, 0.0f, (float)getWindowWidth()-1 );
    mY = constrain( mY, 0.0f, (float)getWindowHeight()-1 );
}

void Walker::render()
{
	gl::color( .68, .68, .68 );
	Rectf box = Rectf( mX - 20, mY - 20, mX + 20, mY + 20 );
	gl::drawSolidRect( box );
	gl::color( 0, 0, 0 );
	gl::drawStrokedRect( box );
}
