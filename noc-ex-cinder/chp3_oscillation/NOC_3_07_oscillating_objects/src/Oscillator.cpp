//
//  Oscillator.cpp
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "Oscillator.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Oscillator::Oscillator( Vec2f windowSize )
{
	mAngle = Vec2f();
	mVelocity = Vec2f( randFloat( -0.05, 0.05 ), randFloat( -0.05, 0.05 ) );
    mAmplitude = Vec2f( randFloat( 20.0, windowSize.x / 2.0 ), randFloat( 20.0, windowSize.y / 2) );
}


void Oscillator::oscillate()
{
	mAngle += mVelocity;
}

void Oscillator::display()
{
	float x = sin( mAngle.x ) * mAmplitude.x;
    float y = sin( mAngle.y ) * mAmplitude.y;
	Vec2f loc = Vec2f( x, y );
	
	glPushMatrix();
	gl::translate( getWindowWidth() / 2, getWindowHeight() / 2 );
	
	gl::color( Color::black() );
	glLineWidth( 2.0 );
	gl::drawLine( Vec2f::zero(), loc );
	gl::drawStrokedEllipse( loc, 16, 16 );
	
	gl::color( ColorA8u::gray ( 127, 127 ) );
	gl::drawSolidEllipse( loc, 16, 16 );
	
    glPopMatrix();
}