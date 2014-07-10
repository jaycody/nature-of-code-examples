//
//  Figure I.2 Bell Curve
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

class Figure_I_2_BellCurveApp : public AppBasic {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
};

void Figure_I_2_BellCurveApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 400, 200 );
}

void Figure_I_2_BellCurveApp::setup()
{
}

void Figure_I_2_BellCurveApp::update()
{
}

void Figure_I_2_BellCurveApp::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
	
	int	  w = getWindowWidth();
	float e = 2.71828183;												// "e", see http://mathforum.org/dr.math/faq/faq.e.html for more info
	float heights[w];													// use an array to store all the "y" values
	float m = 0.0f;														// default mean of 0
	float mouseX = constrain( (float)getMousePos().x, 0.0f, (float)w );	// constrain mouseX to the window borders
	float sd = lmap( mouseX, 0.0f, (float)w, 0.4f, 2.0f );				// standard deviation based on x mouse position
	for( int i = 0; i < w; i++ ) {
		float xcoord = lmap( (float)i, 0.0f, (float)w, -3.0f, 3.0f );
		float sq2pi = sqrt( M_PI_2 );										// square root of 2 * PI
		float xmsq = -1 * (xcoord-m) * (xcoord-m);							// -(x - mu)^2
		float sdsq = sd*sd;												// variance (standard deviation squared)
		heights[i] = ( 1 / (sd * sq2pi) ) * ( pow( e, (xmsq/sdsq) ) );		// P(x) function
	}
	
	gl::color( 0, 0, 0 );
	gl::begin( GL_LINE_STRIP );
	for( int i = 0; i < w - 1; i++ ) {
		float x = (float)i;
		float y = lmap( heights[i], 0.0f, 1.0f, (float)getWindowHeight() - 2.0f, 2.0f );
		gl::vertex( x, y );
	}
	gl::end();
}

CINDER_APP_BASIC( Figure_I_2_BellCurveApp, RendererGl )
