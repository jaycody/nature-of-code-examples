//
//  Example 1-9: Motion 101 Acceleration
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Mover.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_1_9_motion101_accelerationApp : public AppBasic {
public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	Mover *mMover;
};

void NOC_1_9_motion101_accelerationApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 800, 200 );
}

void NOC_1_9_motion101_accelerationApp::setup()
{
	mMover = new Mover();
}

void NOC_1_9_motion101_accelerationApp::update()
{
	mMover->update();
	mMover->checkEdges();
}

void NOC_1_9_motion101_accelerationApp::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
	mMover->display();
}

CINDER_APP_BASIC( NOC_1_9_motion101_accelerationApp, RendererGl )
