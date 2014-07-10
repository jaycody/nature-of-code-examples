//
//  I.9 Noise 3D
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

class Exc_I_9_Noise3DApp : public AppBasic {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	float mIncrement = 0.01f;
	float mZOff = 0.0;			// The noise function's 3rd argument, a global variable that increments once per cycle
	float mZIncrement = 0.02;	// We will increment zoff differently than xoff and yoff
	
	Perlin mPerlin;
};

void Exc_I_9_Noise3DApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 200, 200 );
}

void Exc_I_9_Noise3DApp::setup()
{
	mPerlin = Perlin();
}

void Exc_I_9_Noise3DApp::update()
{
}

void Exc_I_9_Noise3DApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
	
	// create a surface object to apply the pixel values to
	Surface pixelSurface( 200, 200, true );
	float xOff = 0.0; // Start xoff at 0
	
	// For every x,y coordinate in a 2D space, calculate a noise value and produce a brightness value
	for( int x = 0; x < getWindowWidth(); x++ ){
		xOff += mIncrement;
		float yOff = 0.0;
		for( int y=0; y < getWindowHeight(); y++ ){
			yOff += mIncrement;
			
			// Calculate noise and scale by 255
			float bright = ( mPerlin.fBm( xOff, yOff, mZOff ) + 0.5 ) * 255;
			
			// Try using this line instead
//			int bright = randInt( 0, 255 );
			
			// Set each pixel onscreen to a grayscale value
			pixelSurface.setPixel( Vec2i( x, y ), Color8u( bright, bright, bright ) );
		}
	}
	
	gl::draw( gl::Texture( pixelSurface ) );
	mZOff += mZIncrement; // Increment zoff
}

CINDER_APP_BASIC( Exc_I_9_Noise3DApp, RendererGl )
