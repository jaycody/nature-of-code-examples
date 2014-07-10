//
//  I.1 Random Walker Traditional
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

class NOC_I_1_RandomWalkTraditionalApp : public AppBasic {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	Walker *walker;
};

void NOC_I_1_RandomWalkTraditionalApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 800, 200 );
}

void NOC_I_1_RandomWalkTraditionalApp::setup()
{
	gl::clear( Color( 1, 1, 1 ) );
	walker = new Walker();
}

void NOC_I_1_RandomWalkTraditionalApp::update()
{
	walker->step();
}

void NOC_I_1_RandomWalkTraditionalApp::draw()
{
	walker->render();
}

CINDER_APP_BASIC( NOC_I_1_RandomWalkTraditionalApp, RendererGl )
