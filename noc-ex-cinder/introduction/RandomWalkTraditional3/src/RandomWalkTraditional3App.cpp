//
//  Random Walk Traditional 3
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

class RandomWalkTraditional3App : public AppBasic {
public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	Walker *mWalker;
};


void RandomWalkTraditional3App::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 200, 200 );
}

void RandomWalkTraditional3App::setup()
{
	gl::clear( Color( 0, 0, 0 ) );
	// Create a walker object
	mWalker = new Walker();
}

void RandomWalkTraditional3App::update()
{
	mWalker->step();
}

void RandomWalkTraditional3App::draw()
{
	
	mWalker->render();
}

CINDER_APP_BASIC( RandomWalkTraditional3App, RendererGl )
