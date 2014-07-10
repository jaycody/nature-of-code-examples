//
//  Gaussian2
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "cinder/CinderMath.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Gaussian2App : public AppBasic {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	Rand *mGenerator;
	int mWidth;
	int mHeight;
};

void Gaussian2App::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 200, 200 );
}

void Gaussian2App::setup()
{
	gl::clear( Color( 0, 0, 0 ) );
	mGenerator = new Rand();
	mWidth = getWindowWidth();
	mHeight = getWindowHeight();
}

void Gaussian2App::update()
{
}

void Gaussian2App::draw()
{
	gl::enableAlphaBlending();
	
	//create an alpha blended background
	gl::color( 0.0f, 0.0f, 0.0f, 0.01f );
	gl::drawSolidRect( Rectf( 0, 0, mWidth, mHeight ) );
	
	//get 3 gaussian random numbers w/ mean of 0 and standard deviation of 1.0
	float r = (float) mGenerator->nextGaussian();
	float g = (float) mGenerator->nextGaussian();
	float b = (float) mGenerator->nextGaussian();
	
	//define standard deviation and mean
	float sd = 100.0f; float mean = 100.0f;
	//scale by standard deviation and mean
	//also constrain to between (0,255) since we are dealing with color
	r = constrain( ( r * sd ) + mean, 0.0f, 255.0f );
	
	//repeat for g & b
	sd = 20; mean = 200;
	g = constrain( ( g * sd ) + mean, 0.0f, 255.0f );
	sd = 50; mean = 0;
	b = constrain( ( b * sd ) + mean, 0.0f, 255.0f );
	
	//get more gaussian numbers, this time for location
	float xloc = (float) mGenerator->nextGaussian();
	float yloc = (float) mGenerator->nextGaussian();
	sd = mWidth/10;
	mean = mWidth/2;
	xloc = ( xloc * sd ) + mean;
	yloc = ( yloc * sd ) + mean;
	
	//draw an ellipse with gaussian generated color and location
	gl::color( r, g, b );
	gl::drawSolidEllipse( Vec2f( xloc, yloc ), 4.0f, 4.0f );
}

CINDER_APP_BASIC( Gaussian2App, RendererGl )
