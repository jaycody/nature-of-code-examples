//
//  Figure I.5 Noise 1D Graph
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Perlin.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Figure_I_5_Noise1DGraphApp : public AppBasic {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	float mTime = 0.0;
	Perlin mPerlin;
};

void Figure_I_5_Noise1DGraphApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 400, 200 );
}

void Figure_I_5_Noise1DGraphApp::setup()
{
	mPerlin = Perlin();
}

void Figure_I_5_Noise1DGraphApp::update()
{
}

void Figure_I_5_Noise1DGraphApp::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
	
	float xoff = mTime;
	gl::color( 0, 0, 0 );
	glLineWidth( 2.0f );
	gl::begin(GL_LINE_STRIP);
	for( int i = 0; i < getWindowWidth(); i++ ) {
		float y = ( mPerlin.fBm( xoff ) + 0.5f ) * getWindowHeight();
		xoff += 0.01;
		gl::vertex( i, y );
	}
	gl::end();
	mTime += 0.01;
}

CINDER_APP_BASIC( Figure_I_5_Noise1DGraphApp, RendererGl )
