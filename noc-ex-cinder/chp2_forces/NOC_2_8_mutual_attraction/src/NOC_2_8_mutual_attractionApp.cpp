//
//  Example 2-8: Mutual Attraction
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Mover.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_2_8_mutual_attractionApp : public AppBasic {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	vector<Mover>	mMovers;
	int				mMoverAmt = 20;
};

void NOC_2_8_mutual_attractionApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 800, 200 );
}

void NOC_2_8_mutual_attractionApp::setup()
{
	mMovers = vector<Mover>();
	for( int i = 0; i < mMoverAmt; i++ )
	{
		mMovers.push_back( Mover( randFloat( 0.1, 2.0 ), randFloat( getWindowWidth() ), randFloat( getWindowHeight() ) ) );
	}
}

void NOC_2_8_mutual_attractionApp::update()
{
	for( int i = 0; i < mMovers.size(); i++ ) {
		for( int j = 0; j < mMovers.size(); j++ ) {
			if( i != j ) {
				Vec2f force = mMovers[j].attract( mMovers[i] );
				mMovers[i].applyForce( force );
			}
		}
		mMovers[i].update();
	}
}

void NOC_2_8_mutual_attractionApp::draw()
{
	gl::enableAlphaBlending();
	gl::clear( Color::white() );
	
	for( int i = 0; i < mMovers.size(); i++ )
	{
		mMovers[i].display();
	}
}

CINDER_APP_BASIC( NOC_2_8_mutual_attractionApp, RendererGl )
