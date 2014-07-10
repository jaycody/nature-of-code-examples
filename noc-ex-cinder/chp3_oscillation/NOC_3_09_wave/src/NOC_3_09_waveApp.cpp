//
//  Example 3-9: Wave
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

class NOC_3_09_waveApp : public AppBasic {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	float mStartAngle;
	float mAngleVel;
};

void NOC_3_09_waveApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 800, 200 );
}

void NOC_3_09_waveApp::setup()
{
	mStartAngle = 0;
	mAngleVel = 0.23;
}

void NOC_3_09_waveApp::update()
{
	mStartAngle += 0.015;
}

void NOC_3_09_waveApp::draw()
{
	gl::enableAlphaBlending();
	gl::clear( Color( 1, 1, 1 ) );
	
	float angle = mStartAngle;
	
	for( int x = 0; x <= getWindowWidth(); x += 24 ) {
		float y = lmap( sin( angle ), -1.0f, 1.0f, 0.0f, ( float )getWindowHeight() );
		gl::color( 0, 0, 0 );
		glLineWidth( 2.0 );
		gl::drawStrokedEllipse( Vec2f( x, y ), 24, 24);
		
		gl::color( ColorA8u::gray( 0, 50 ) );
		gl::drawSolidEllipse( Vec2f( x, y ), 24, 24);

		angle += mAngleVel;
	}
}

CINDER_APP_BASIC( NOC_3_09_waveApp, RendererGl )
