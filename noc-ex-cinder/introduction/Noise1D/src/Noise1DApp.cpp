//
//  Noise 1D
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Perlin.h"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Noise1DApp : public AppBasic {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	float mXOff;
	float mXIncrement;
	Perlin mPerlin;
};

void Noise1DApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 200, 200 );
}

void Noise1DApp::setup()
{
	gl::clear( Color( 0, 0, 0 ) ); 
	mXOff = 0.0;
	mXIncrement = 0.01;
	mPerlin = Perlin();
}

void Noise1DApp::update()
{
}

void Noise1DApp::draw()
{
	gl::enableAlphaBlending();
	
	// Create an alpha blended background
	gl::color( 0, 0, 0, .01 );
	gl::drawSolidRect( Rectf( 0.0, 0.0, (float)getWindowWidth(), (float)getWindowHeight() ) );
	
//	float n = randFloat( 0.0, (float)getWindowWidth() );  // Try this line instead of noise
	
	// Get a noise value based on xoff and scale it according to the window's width
	float n = (mPerlin.fBm( mXOff ) + .5) * (float)getWindowWidth();
	
	// With each cycle, increment xoff
	mXOff += mXIncrement;
	
	// Draw the ellipse at the value produced by perlin noise
	gl::color( .78, .78, .78 );
	gl::drawSolidEllipse( Vec2f( n, getWindowHeight() / 2 ), 8, 8 );
	
}

CINDER_APP_BASIC( Noise1DApp, RendererGl )
