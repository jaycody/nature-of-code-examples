//
//  Example 3-4: Polar to Cartesian
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//
//  Convert a polar coordinate (r,theta) to cartesian (x,y):
//  x = r * cos(theta)
//  y = r * sin(theta)
//

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_3_04_PolarToCartesianApp : public AppBasic {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	float mR, mTheta;
};

void NOC_3_04_PolarToCartesianApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 800, 200 );
}

void NOC_3_04_PolarToCartesianApp::setup()
{
	// Initialize all values
	mR = getWindowHeight() * 0.45;
	mTheta = 0.0;
	
	// clear out the window with white
	gl::clear( Color( 1, 1, 1 ) );
}

void NOC_3_04_PolarToCartesianApp::update()
{
}

void NOC_3_04_PolarToCartesianApp::draw()
{
	// trail
	/*gl::enableAlphaBlending();
	gl::color( ColorA8u::gray( 255, 5 ) );
	gl::drawSolidRect( getWindowBounds() );*/
    
	// no trail
	gl::clear( Color( 1, 1, 1 ) );
	
	glPushMatrix();
	// Translate the origin point to the center of the screen
	gl::translate( getWindowSize() / 2 );
	
	// Convert polar to cartesian
	float x = mR * cos( mTheta );
	float y = mR * sin( mTheta );
	Vec2f loc = Vec2f( x, y );
	
	// draw line
	glLineWidth( 2.0 );
	gl::color( Color::black() );
	gl::drawLine( Vec2f::zero(), loc );
	
	// draw stroked circle
	gl::drawStrokedEllipse( loc, 24, 24 );
	
	// draw solid circle
	gl::color( Color8u::gray( 127 ) );
	gl::drawSolidEllipse( loc, 24, 24 );
	
	// Increase the angle over time
	mTheta += 0.02;
	
	glPopMatrix();
}

CINDER_APP_BASIC( NOC_3_04_PolarToCartesianApp, RendererGl )
