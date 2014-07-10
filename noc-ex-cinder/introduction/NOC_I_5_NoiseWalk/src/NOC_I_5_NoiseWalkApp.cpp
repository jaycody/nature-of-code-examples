//
//  I.5 Noise Walk
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

class NOC_I_5_NoiseWalkApp : public AppBasic {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	Walker *mWalker;
};

void NOC_I_5_NoiseWalkApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 800, 200 );
	settings->setFrameRate( 30.0f );
}

void NOC_I_5_NoiseWalkApp::setup()
{
	mWalker = new Walker();
}

void NOC_I_5_NoiseWalkApp::update()
{
	mWalker->walk();
}

void NOC_I_5_NoiseWalkApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 1, 1, 1 ) );
	
	mWalker->display();
}

CINDER_APP_BASIC( NOC_I_5_NoiseWalkApp, RendererGl )
