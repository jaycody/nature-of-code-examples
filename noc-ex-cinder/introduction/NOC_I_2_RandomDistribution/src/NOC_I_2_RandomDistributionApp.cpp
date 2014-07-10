#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_I_2_RandomDistributionApp : public AppBasic {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	
	vector<float> mRandomCounts;
};

void NOC_I_2_RandomDistributionApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 800, 200 );
}


void NOC_I_2_RandomDistributionApp::setup()
{
	mRandomCounts.resize( 20 );
}

void NOC_I_2_RandomDistributionApp::mouseDown( MouseEvent event )
{
}

void NOC_I_2_RandomDistributionApp::update()
{
}

void NOC_I_2_RandomDistributionApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
	
	// Pick a random number and increase the count
	int index = randInt( mRandomCounts.size() );
	mRandomCounts[index]++;
	
	// Draw a rectangle to graph results
	
	int w = getWindowWidth() / mRandomCounts.size();
	for( int i = 0; i < mRandomCounts.size(); i++ ) {
		float x = (i*w);
		float y = getWindowHeight() - mRandomCounts[i];
		Rectf box = Rectf( x, y, x + w - 1, y + mRandomCounts[i] );
		gl::color( .5, .5, .5 );
		gl::drawSolidRect( box );
		gl::color( 0, 0, 0 );
		gl::drawStrokedRect( box );
	}
}

CINDER_APP_BASIC( NOC_I_2_RandomDistributionApp, RendererGl )
