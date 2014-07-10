//
//  Random Walker Vectors
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class SimpleProbabilityApp : public AppBasic {
  public:
	void prepareSettings( Settings *settings);
	void setup();
	void update();
	void draw();
	
	int mX, mY;
};

void SimpleProbabilityApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 200, 200 );
}

void SimpleProbabilityApp::setup()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
	mX = 0;
	mY = 0;
}

void SimpleProbabilityApp::update()
{
}

void SimpleProbabilityApp::draw()
{
	gl::enableAlphaBlending(); // add this to allow the drawing of semi-transparent shapes
	
	//create an alpha blended background
	gl::color( 0.0f, 0.0f, 0.0f, 0.01f );
	gl::drawSolidRect( Rectf( 0.0f, 0.0f, getWindowWidth(), getWindowHeight() ) );
	
	//calculate a probability between 0 and 100% based on mouseX location
	float prob = ( getMousePos().x / (float) getWindowWidth() );
	
	//get a random floating point value between 0 and 1
	float r = randFloat( 1.0f );
	
	//test the random value against the probability and trigger an event
	if( r < prob ) {
		gl::color( 1.0f, 1.0f, 1.0f );
		gl::drawSolidEllipse( Vec2f( mX, mY ), 5.0f, 5.0f );
	}
	
	// X and Y walk through a grid
	mX = ( mX + 10 ) % getWindowWidth();
	if( mX == 0 ) mY = ( mY + 10 ) % getWindowWidth();
}

CINDER_APP_BASIC( SimpleProbabilityApp, RendererGl )
