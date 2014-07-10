//
//  Example 1-2: Bouncing Ball, with PVector!
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

class NOC_1_2_bouncingball_vectorsApp : public AppBasic {
  public:
	void prepareSettings( Settings *settings);
	void setup();
	void update();
	void draw();
	
	Vec2f mLocation;
	Vec2f mVelocity;
};

void NOC_1_2_bouncingball_vectorsApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 200, 200 );
}

void NOC_1_2_bouncingball_vectorsApp::setup()
{
	gl::clear( Color( 1, 1, 1 ) );
	mLocation = Vec2f( 100.0, 100.0 );
	mVelocity = Vec2f( 2.5, 5.0 );
}

void NOC_1_2_bouncingball_vectorsApp::update()
{
}

void NOC_1_2_bouncingball_vectorsApp::draw()
{
	gl::enableAlphaBlending();
	gl::color( 1, 1, 1, 0.01f );
	gl::drawSolidRect( Rectf( 0.0, 0.0, getWindowWidth(), getWindowHeight() ) );
	
	// Add the current speed to the location.
	mLocation += mVelocity;
	
	if ( ( mLocation.x > getWindowWidth() ) || ( mLocation.x < 0 ) ) {
		mVelocity.x = mVelocity.x * -1;
	}
	if ( ( mLocation.y > getWindowHeight() ) || ( mLocation.y < 0 ) ) {
		mVelocity.y = mVelocity.y * -1;
	}
	
	// Display circle at x location
	gl::color( .68, .68, .68 );
	gl::drawSolidEllipse( mLocation, 8, 8 );
	
	gl::color( 0, 0, 0 );
	gl::drawStrokedEllipse( mLocation, 8, 8 );
}

CINDER_APP_BASIC( NOC_1_2_bouncingball_vectorsApp, RendererGl )
