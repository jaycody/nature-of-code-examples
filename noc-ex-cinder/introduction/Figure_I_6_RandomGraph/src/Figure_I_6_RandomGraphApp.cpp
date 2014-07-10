//
//  Figure I.6 Random Graph
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Figure_I_6_RandomGraphApp : public AppBasic {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	bool mDone = false;
};

void Figure_I_6_RandomGraphApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 400, 200 );
}

void Figure_I_6_RandomGraphApp::setup()
{
}

void Figure_I_6_RandomGraphApp::update()
{
}

void Figure_I_6_RandomGraphApp::draw()
{
	if( mDone ) return;
	
	gl::clear( Color( 1, 1, 1 ) );
	
	gl::color( 0, 0, 0 );
	glLineWidth( 2.0f );
	gl::begin( GL_LINE_STRIP );
	for( int i = 0; i < getWindowWidth(); i++ ) {
		float y = randFloat( 0.0f, (float)getWindowHeight() );
		gl::vertex( i, y );
	}
	gl::end();
	
	mDone = true;
}

CINDER_APP_BASIC( Figure_I_6_RandomGraphApp, RendererGl )
