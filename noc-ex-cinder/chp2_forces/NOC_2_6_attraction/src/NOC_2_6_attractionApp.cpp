//
//  Example 2-6: Attraction
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Mover.h"
#include "Attractor.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_2_6_attractionApp : public AppBasic {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );
	void mouseUp( MouseEvent event );
	void update();
	void draw();
	
	Mover		mMover;
	Attractor	mAttractor;
};

void NOC_2_6_attractionApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 800, 200 );
}

void NOC_2_6_attractionApp::setup()
{
	mAttractor = Attractor( Vec2f( getWindowWidth() / 2, getWindowHeight() / 2 ) );
}

void NOC_2_6_attractionApp::mouseDown( MouseEvent event )
{
	mAttractor.clicked( getMousePos() );
}

void NOC_2_6_attractionApp::mouseUp(cinder::app::MouseEvent event)
{
	mAttractor.stopDragging();
}

void NOC_2_6_attractionApp::update()
{
	Vec2f force = mAttractor.attract( mMover );
	mMover.applyForce( force );
	mMover.update();
	
	mAttractor.drag( getMousePos() );
	mAttractor.hover( getMousePos() );
}

void NOC_2_6_attractionApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 1, 1, 1 ) );
	
	mAttractor.display();
	mMover.display();
}

CINDER_APP_BASIC( NOC_2_6_attractionApp, RendererGl )
