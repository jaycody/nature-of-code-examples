//
//  Random Walk Noise
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//
//


#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Walker.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class RandomWalkNoiseApp : public AppBasic {
public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	Walker *mWalker;
};


void RandomWalkNoiseApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 640, 360 );
	settings->setFrameRate( 30.0f );
}

void RandomWalkNoiseApp::setup()
{
	gl::clear( Color( 0, 0, 0 ) );
	// Create a walker object
	mWalker = new Walker();
}

void RandomWalkNoiseApp::update()
{
	mWalker->step();
}

void RandomWalkNoiseApp::draw()
{
	
	mWalker->render();
}

CINDER_APP_BASIC( RandomWalkNoiseApp, RendererGl )
