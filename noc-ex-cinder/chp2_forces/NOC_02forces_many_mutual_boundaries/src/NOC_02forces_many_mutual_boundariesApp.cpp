//
//  Forces: Forces Many Mutual Boundaries
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

class NOC_02forces_many_mutual_boundariesApp : public AppBasic {
public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	vector<Mover>	mMovers;
	int				mMoverAmt = 20;
};

void NOC_02forces_many_mutual_boundariesApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 800, 200 );
}

void NOC_02forces_many_mutual_boundariesApp::setup()
{
	mMovers = vector<Mover>();
	for( int i = 0; i < mMoverAmt; i++ )
	{
		mMovers.push_back( Mover( randFloat( 1.0, 2.0 ), randFloat( getWindowWidth() ), randFloat( getWindowHeight() ) ) );
	}
}

void NOC_02forces_many_mutual_boundariesApp::update()
{
	for( int i = 0; i < mMovers.size(); i++ ) {
		for( int j = 0; j < mMovers.size(); j++ ) {
			if( i != j ) {
				Vec2f force = mMovers[j].attract( mMovers[i] );
				mMovers[i].applyForce( force );
			}
		}
		mMovers[i].boundaries();
		mMovers[i].update();
	}
}

void NOC_02forces_many_mutual_boundariesApp::draw()
{
	gl::enableAlphaBlending();
	gl::clear( Color::white() );
	
	for( int i = 0; i < mMovers.size(); i++ )
	{
		mMovers[i].display();
	}
}

CINDER_APP_BASIC( NOC_02forces_many_mutual_boundariesApp, RendererGl )
