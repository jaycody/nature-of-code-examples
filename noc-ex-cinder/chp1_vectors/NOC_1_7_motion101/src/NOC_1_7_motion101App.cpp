//
//  Example 1-7: Motion 101
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

class NOC_1_7_motion101App : public AppBasic {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	Mover *mMover;
};

void NOC_1_7_motion101App::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 200, 200 );
}

void NOC_1_7_motion101App::setup()
{
	mMover = new Mover();
}

void NOC_1_7_motion101App::update()
{
	mMover->update();
	mMover->checkEdges();
}

void NOC_1_7_motion101App::draw()
{
	gl::clear( Color( 1, 1, 1 ) );	
	mMover->display();
}

CINDER_APP_BASIC( NOC_1_7_motion101App, RendererGl )
