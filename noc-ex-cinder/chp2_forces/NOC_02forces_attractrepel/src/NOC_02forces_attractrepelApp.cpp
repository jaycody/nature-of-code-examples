//
//  Forces: Attract - Repel
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Mover.h"
#include "Attractor.h"

using namespace ci;
using namespace ci::app;
using namespace std;

static const float GRAVITY = 1.0;

class NOC_02forces_attractrepelApp : public AppBasic {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	
	vector<Mover>	mMovers;
	int				mMoverAmt = 20;
	Attractor		mAttractor;
};

void NOC_02forces_attractrepelApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 800, 200 );
}

void NOC_02forces_attractrepelApp::setup()
{
	mMovers = vector<Mover>();
	for( int i = 0; i < mMoverAmt; i++ )
	{
		mMovers.push_back( Mover( randFloat( 4.0, 12.0 ), randFloat( getWindowWidth() ), randFloat( getWindowHeight() ), GRAVITY ) );
	}
	mAttractor = Attractor( GRAVITY, getWindowSize() / 2 );

}

void NOC_02forces_attractrepelApp::mouseDown( MouseEvent event )
{
}

void NOC_02forces_attractrepelApp::update()
{
	for( int i = 0; i < mMovers.size(); i++ )
	{
		for (int j = 0; j < mMovers.size(); j++)
		{
			if( i != j )
			{
				Vec2f force = mMovers[j].repel( mMovers[i] );
				mMovers[i].applyForce( force );
			}
		}
		Vec2f force = mAttractor.attract( mMovers[i] );
		mMovers[i].applyForce( force );
		mMovers[i].update();
	}
}

void NOC_02forces_attractrepelApp::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
	
	mAttractor.display();
	for( int i = 0; i < mMovers.size(); i++ )
	{
		mMovers[i].display();
	}
}


CINDER_APP_BASIC( NOC_02forces_attractrepelApp, RendererGl )
