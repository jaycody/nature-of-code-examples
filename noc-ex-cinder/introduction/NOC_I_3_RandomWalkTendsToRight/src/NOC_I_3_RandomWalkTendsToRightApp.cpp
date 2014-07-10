//
//  I.3 Random Walker Tends to Right
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

class NOC_I_3_RandomWalkTendsToRightApp : public AppBasic {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	Walker *mWalker;	
};

void NOC_I_3_RandomWalkTendsToRightApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 800, 200 );
}

void NOC_I_3_RandomWalkTendsToRightApp::setup()
{
	gl::clear( Color( 1, 1, 1 ) );
	mWalker = new Walker();
}

void NOC_I_3_RandomWalkTendsToRightApp::update()
{
	mWalker->step();
}

void NOC_I_3_RandomWalkTendsToRightApp::draw()
{
	mWalker->render();
}

CINDER_APP_BASIC( NOC_I_3_RandomWalkTendsToRightApp, RendererGl )
