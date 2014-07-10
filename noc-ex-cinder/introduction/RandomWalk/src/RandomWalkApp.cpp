//
//  Random Walker (No Vectors)
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Walker.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class RandomWalkApp : public AppBasic {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	Walker *mWalker;
};


void RandomWalkApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 400, 400 );
	settings->setFrameRate( 30.0f );
}

void RandomWalkApp::setup()
{
	mWalker = new Walker();
}

void RandomWalkApp::update()
{
	mWalker->walk();
}

void RandomWalkApp::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
	mWalker->render();
}

CINDER_APP_BASIC( RandomWalkApp, RendererGl )
