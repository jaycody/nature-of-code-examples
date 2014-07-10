//
//  Example 3-2: Forces Angular Motion
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

class NOC_3_02_forces_angular_motionApp : public AppBasic {
public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	vector<Mover>	mMovers;	// using a vector instead of an array
	int				mMoverAmt = 20;
	Attractor		mAttractor;
};

void NOC_3_02_forces_angular_motionApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 800, 200 );
}

void NOC_3_02_forces_angular_motionApp::setup()
{
	mMovers = vector<Mover>();
	for( int i = 0; i < mMoverAmt; i++ )
	{
		mMovers.push_back( Mover( randFloat( 0.1, 2.0 ), randFloat( getWindowWidth() ), randFloat( getWindowHeight() ) ) );
	}
	mAttractor = Attractor( Vec2f( getWindowWidth() / 2, getWindowHeight() / 2 ) );
}

void NOC_3_02_forces_angular_motionApp::update()
{
	for( int i = 0; i < mMovers.size(); i++ )
	{
		Vec2f force = mAttractor.attract( mMovers[i] );
		mMovers[i].applyForce( force );
		mMovers[i].update();
	}
}

void NOC_3_02_forces_angular_motionApp::draw()
{
	//gl::clear( Color( 1, 1, 1 ) );
	
	// for motion trails
	gl::color( ColorA8u::gray( 255, 5 ) );
	gl::drawSolidRect( getWindowBounds() );
	
	gl::enableAlphaBlending();
	
	mAttractor.display();
	for( int i = 0; i < mMovers.size(); i++ )
	{
		mMovers[i].display();
	}
}

CINDER_APP_BASIC( NOC_3_02_forces_angular_motionApp, RendererGl )
