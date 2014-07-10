//
//  I.4 Gaussian
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

class NOC_I_4_GaussianApp : public AppBasic {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	Rand *mGenerator;
};

void NOC_I_4_GaussianApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 800, 200 );
	mGenerator = new Rand();
}

void NOC_I_4_GaussianApp::setup()
{
	gl::clear( Color( 1, 1, 1 ) );
}

void NOC_I_4_GaussianApp::update()
{
}

void NOC_I_4_GaussianApp::draw()
{
	gl::enableAlphaBlending();
	
	// Get a gaussian random number w/ mean of 0 and standard deviation of 1.0
	float xloc = (float) mGenerator->nextGaussian();
	
	float sd = 60;								// Define a standard deviation
	float mean = getWindowWidth()/2;			// Define a mean value (middle of the screen along the x-axis)
	xloc = ( xloc * sd ) + mean;				// Scale the gaussian random number by standard deviation and mean
	
	gl::color( 0, 0, 0, .1 );
	gl::drawSolidEllipse( Vec2f( xloc, getWindowHeight()/2 ), 8, 8 );   // Draw an ellipse at our "normal" random location
}

CINDER_APP_BASIC( NOC_I_4_GaussianApp, RendererGl )
