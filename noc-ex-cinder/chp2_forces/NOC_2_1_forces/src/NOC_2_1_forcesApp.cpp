//
//  Example 2-1: Forces
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

class NOC_2_1_forcesApp : public AppBasic {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	Mover mMover;
};

void NOC_2_1_forcesApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 800, 200 );
}

void NOC_2_1_forcesApp::setup()
{
	mMover = Mover();
}

void NOC_2_1_forcesApp::update()
{
}

void NOC_2_1_forcesApp::draw()
{
	// clear out the window with black
	gl::clear( Color::white() );
	
	Vec2f wind = Vec2f( 0.01, 0.0 );
	Vec2f gravity = Vec2f( 0, 0.1 );
	mMover.applyForce( wind );
	mMover.applyForce( gravity );
	
	
	mMover.update();
	mMover.display();
	mMover.checkEdges();
}

CINDER_APP_BASIC( NOC_2_1_forcesApp, RendererGl )
