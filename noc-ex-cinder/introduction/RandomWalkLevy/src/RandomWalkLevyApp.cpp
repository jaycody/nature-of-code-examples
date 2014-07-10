//
//  Random Walker
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

class RandomWalkLevyApp : public AppBasic {
public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	Walker *mWalker;
};


void RandomWalkLevyApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 640, 480 );
}

void RandomWalkLevyApp::setup()
{
	gl::clear( Color( 0, 0, 0 ) );
	// Create a walker object
	mWalker = new Walker();
}

void RandomWalkLevyApp::update()
{
	mWalker->step();
}

void RandomWalkLevyApp::draw()
{
	mWalker->render();
}

CINDER_APP_BASIC( RandomWalkLevyApp, RendererGl )
