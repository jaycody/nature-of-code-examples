//
//  Example 3-6: Simple Harmonic Motion 2
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_3_06_simple_harmonic_mot_2App : public AppBasic {
public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	float mAngle, mAngleVelocity;
};

void NOC_3_06_simple_harmonic_mot_2App::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 640, 360 );
}

void NOC_3_06_simple_harmonic_mot_2App::setup()
{
	gl::clear( Color( 1, 1, 1 ) );
	mAngle = 0;
	mAngleVelocity = 0.03;
}

void NOC_3_06_simple_harmonic_mot_2App::update()
{
}

void NOC_3_06_simple_harmonic_mot_2App::draw()
{
	// trail
	/*gl::enableAlphaBlending();
	 gl::color( ColorA8u::gray( 255, 5 ) );
	 gl::drawSolidRect( getWindowBounds() );*/
    
	// no trail
	gl::clear( Color( 1, 1, 1 ) );
	
	float amplitude = 300.0f;
	float x = amplitude * cos( mAngle );
	mAngle += mAngleVelocity;
	Vec2f loc = Vec2f( x, 0 );
	
	glPushMatrix();
	// Translate the origin point to the center of the screen
	gl::translate( getWindowSize() / 2 );
	
	// draw line
	gl::color( Color::black() );
	gl::drawLine( Vec2f::zero(), loc );
	
	// draw stroked circle
	gl::drawStrokedEllipse( loc, 10, 10 );
	
	// draw solid circle
	gl::color( Color8u::gray( 127 ) );
	gl::drawSolidEllipse( loc, 10, 10 );
	glPopMatrix();
}

CINDER_APP_BASIC( NOC_3_06_simple_harmonic_mot_2App, RendererGl )
