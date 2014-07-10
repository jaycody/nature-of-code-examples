//
//  Example 3-5: Simple Harmonic Motion
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

class NOC_3_05_simple_harmonic_motApp : public AppBasic {
public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
};

void NOC_3_05_simple_harmonic_motApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 800, 200 );
}

void NOC_3_05_simple_harmonic_motApp::setup()
{
	gl::clear( Color( 1, 1, 1 ) );
}

void NOC_3_05_simple_harmonic_motApp::update()
{
}

void NOC_3_05_simple_harmonic_motApp::draw()
{
	// trail
	/*gl::enableAlphaBlending();
	 gl::color( ColorA8u::gray( 255, 5 ) );
	 gl::drawSolidRect( getWindowBounds() );*/
    
	// no trail
	gl::clear( Color( 1, 1, 1 ) );
	
	float period = 120.0f;
	float amplitude = 300.0f;
	// Calculating horizontal location according to formula for simple harmonic motion
	float x = amplitude * cos( ( M_PI * 2 ) * ( getElapsedFrames() / period ) );
	Vec2f loc = Vec2f( x, 0 );
	
	glPushMatrix();
	// Translate the origin point to the center of the screen
	gl::translate( getWindowSize() / 2 );
	
	// draw line
	glLineWidth( 2.0 );
	gl::color( Color::black() );
	gl::drawLine( Vec2f::zero(), loc );
	
	// draw stroked circle
	gl::drawStrokedEllipse( loc, 24, 24 );
	
	// draw solid circle
	gl::color( Color8u::gray( 127 ) );
	gl::drawSolidEllipse( loc, 24, 24 );
	glPopMatrix();
}

CINDER_APP_BASIC( NOC_3_05_simple_harmonic_motApp, RendererGl )
