//
//  Noise 2D
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Perlin.h"
#include "cinder/gl/Texture.h"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Noise2DApp : public AppBasic {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	float mIncrement = 0.02;
	Surface mPixelSurface;
};

void Noise2DApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 800, 200 );
}

void Noise2DApp::setup()
{
	mPixelSurface = Surface( getWindowWidth(), getWindowHeight(), true );
	Perlin perlin = Perlin();
	float xOff = 0.0;
	
	// Optional: adjust noise detail here
//	perlin.setOctaves( 8.0 );
	
	// For every x,y coordinate in a 2D space, calculate a noise value and produce a brightness value
	for( int x = 0; x < getWindowWidth(); x++ )
	{
		xOff += mIncrement;			// Increment xoff
		float yOff = 0.0;			// For every xoff, start yoff at 0
		for( int y = 0; y < getWindowHeight(); y++ )
		{
			yOff += mIncrement;		// Increment yoff
			
			// Calculate noise and scale by 255
			float bright = ( perlin.fBm( xOff, yOff ) + 0.5 ) * 255;
			
			// Try using this line instead
			//			int bright = randInt( 0, 255 );
			
			// Set each pixel onscreen to a grayscale value
			mPixelSurface.setPixel( Vec2i( x, y ), Color8u( bright, bright, bright ) );
		}
	}
}

void Noise2DApp::update()
{
}

void Noise2DApp::draw()
{
	gl::draw( gl::Texture( mPixelSurface ) );
}

CINDER_APP_BASIC( Noise2DApp, RendererGl )
