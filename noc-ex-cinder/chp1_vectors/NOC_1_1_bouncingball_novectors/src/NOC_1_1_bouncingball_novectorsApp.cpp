//
//  Example 1-1: Bouncing Ball, no vectors
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

class NOC_1_1_bouncingball_novectorsApp : public AppBasic {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	float mX;
	float mY;
	float mXSpeed;
	float mYSpeed;
};

void NOC_1_1_bouncingball_novectorsApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 800, 200 );
}

void NOC_1_1_bouncingball_novectorsApp::setup()
{
	mX = 100;
	mY = 100;
	mXSpeed = 2.5;
	mYSpeed = 2;
}

void NOC_1_1_bouncingball_novectorsApp::update()
{
}

void NOC_1_1_bouncingball_novectorsApp::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
	
	// Add the current speed to the location.
	mX = mX + mXSpeed;
	mY = mY + mYSpeed;
	
	if( ( mX > getWindowWidth() ) || ( mX < 0 ) ) {
		mXSpeed = mXSpeed * -1;
	}
	if( ( mY > getWindowHeight() ) || ( mY < 0 ) ) {
		mYSpeed = mYSpeed * -1;
	}
	
	// Display circle at x location
	gl::color( .5, .5, .5 );
	gl::drawSolidEllipse( Vec2f( mX, mY ), 24, 24 );
	
	glLineWidth( 2.0 );
	gl::color( 0, 0, 0 );
	gl::drawStrokedEllipse( Vec2f( mX, mY ), 24, 24 );
}

CINDER_APP_BASIC( NOC_1_1_bouncingball_novectorsApp, RendererGl )
