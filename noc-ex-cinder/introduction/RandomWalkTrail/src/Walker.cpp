//
//  Walker.cpp
//  Random Walk Trail
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
	Vec2f vel = Vec2f( randFloat( -2.0f, 2.0f ), randFloat( -2.0f, 2.0f ) );
	mLoc += vel;
    
	// Stay on the screen
    mLoc.x = constrain( mLoc.x, 0.0f, (float)getWindowWidth() - 1 );
    mLoc.y = constrain( mLoc.y, 0.0f, (float)getWindowHeight() - 1 );
	
	mHistory.push_back( Vec2f( mLoc.x, mLoc.y ) );
	if(mHistory.size() > 1000) {
		mHistory.pop_front();
	}
}

void Walker::display()
{
	
	gl::color( .68, .68, .68 );
	Rectf box = Rectf( mLoc.x - 8, mLoc.y - 8, mLoc.x + 8, mLoc.y + 8 );
	gl::drawSolidRect( box );
	gl::color( 0, 0, 0 );
	gl::drawStrokedRect( box );
	
	
	gl::begin(GL_LINE_STRIP);
    for( Vec2f v: mHistory ) {
		gl::vertex( v.x, v.y );
    };
	gl::end();
	
	
	// Using an iterator
	/*
	gl::color(0, 0, 0);
	list<Vec2f>::iterator it;
	//Particle particle;
	gl::begin(GL_LINE_STRIP);
	for(it=mHistory.begin(); it != mHistory.end(); it++)
	{
		Vec2f v = *it;
		gl::vertex(v.x, v.y);
	}
	gl::end();
	*/
}
