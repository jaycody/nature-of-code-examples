//
//  Multiple Probability
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

class MultipleProbabilityApp : public AppBasic {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	int mX, mY;
	int mWidth, mHeight;
};

void MultipleProbabilityApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 200, 200 );	
}

void MultipleProbabilityApp::setup()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
	
	mWidth = getWindowWidth();
	mHeight = getWindowHeight();
	mX = mY = 0;
}

void MultipleProbabilityApp::update()
{
}

void MultipleProbabilityApp::draw()
{
	//create an alpha blended background
	gl::enableAlphaBlending();
	gl::color( 0, 0, 0, 0.01f );
	gl::drawSolidRect( Rectf( 0.0f, 0.0f, mWidth, mHeight ) );
	
	//probabilities for 3 different cases (these need to add up to 100% since something always occurs here!)
	float p1 = 0.05;				// 5% chance of pure white occurring
	float p2 = 0.80 + p1;			// 80% chance of gray occuring
	
    float num = randFloat( 1.0f );	// pick a random number between 0 and 1
	Color fillCol;
	if (num <p1) {
		fillCol = Color( 1, 1, 1 );
	} else if (num < p2) {
		fillCol = Color( .58, .58, .58 );
	} else {
		fillCol = Color( 0, 0, 0 );
	}
	
	gl::color( fillCol );
	Rectf box = Rectf( mX, mY, mX + 10, mY + 10 );
	gl::drawSolidRect( box );
	
	// draw stroked box
	gl::color( .78, .78, .78 );
	gl::drawStrokedRect( box );
	
	// X and Y walk through a grid
	console() << mY << endl;
	mX = (mX + 10) % mWidth;
	if( mX == 0 ) mY = (mY + 10) % mWidth;
	
}

CINDER_APP_BASIC( MultipleProbabilityApp, RendererGl )
