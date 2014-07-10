//
//  Example 3-7: Oscillating Objects
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Oscillator.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_3_07_oscillating_objectsApp : public AppBasic {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	// An array of objects
	vector<Oscillator>	mOscillators;	// using a vector instead of an array
	int					mOscAmt = 10;
};

void NOC_3_07_oscillating_objectsApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 800, 200 );
}

void NOC_3_07_oscillating_objectsApp::setup()
{
	gl::clear( Color( 1, 1, 1 ) );
	
	mOscillators = vector<Oscillator>();
	for( int i = 0; i < mOscAmt; i++ )
	{
		mOscillators.push_back( Oscillator( getWindowSize() ) );
	}
}

void NOC_3_07_oscillating_objectsApp::update()
{
	for (int i = 0; i < mOscillators.size(); i++) {
		mOscillators[i].oscillate();
	}
}

void NOC_3_07_oscillating_objectsApp::draw()
{
	// trail
	gl::enableAlphaBlending();
	 gl::color( ColorA8u::gray( 255, 10 ) );
	 gl::drawSolidRect( getWindowBounds() );
    
	// no trail
	//	gl::clear( Color( 1, 1, 1 ) );
	
	// Run all objects
	for (int i = 0; i < mOscillators.size(); i++) {
		mOscillators[i].display();
	}
}

CINDER_APP_BASIC( NOC_3_07_oscillating_objectsApp, RendererGl )
