//
//  Example 3-8: Static Wave Lines
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/CinderMath.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_3_08_static_wave_linesApp : public AppBasic {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	float mAngle;
	float mAngleVel;
};

void NOC_3_08_static_wave_linesApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 800, 200 );
}

void NOC_3_08_static_wave_linesApp::setup()
{
	mAngleVel = 0.1;
}

void NOC_3_08_static_wave_linesApp::update()
{
}

void NOC_3_08_static_wave_linesApp::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
	
	glLineWidth( 2.0 );
	gl::color(0, 0, 0 );
	
	float mAngle = 0;
	gl::begin( GL_LINE_STRIP );
	for( int x = 0; x <= getWindowWidth(); x += 5 ) {
		float y = lmap( sin( mAngle ), -1.0f, 1.0f, 0.0f, ( float )getWindowHeight() );
		gl::vertex( Vec2f( x, y ) );
		mAngle += mAngleVel;
	}
	gl::end();
}

CINDER_APP_BASIC( NOC_3_08_static_wave_linesApp, RendererGl )
