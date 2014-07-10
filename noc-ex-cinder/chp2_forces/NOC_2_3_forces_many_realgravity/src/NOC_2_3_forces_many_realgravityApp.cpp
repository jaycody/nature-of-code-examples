//
//  Example 2-3: Forces Many Real Gravity
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

class NOC_2_3_forces_many_realgravityApp : public AppBasic {
public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	vector<Mover> mMovers;	// using a vector instead of an array
	int mMoverAmt = 20;
};

void NOC_2_3_forces_many_realgravityApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 800, 200 );
}

void NOC_2_3_forces_many_realgravityApp::setup()
{
	mMovers = vector<Mover>();
	for( int i = 0; i < mMoverAmt; i++ ){
		mMovers.push_back( Mover( randFloat( 0.1, 4.0 ), 0.0, 0.0 ) );
	}}

void NOC_2_3_forces_many_realgravityApp::update()
{
	for( int i = 0; i < mMovers.size(); i++ ) {
		Vec2f wind = Vec2f( 0.01, 0.0 );
		Vec2f gravity = Vec2f( 0, 0.1 * mMovers[i].mMass );
		mMovers[i].applyForce( wind );
		mMovers[i].applyForce( gravity );
		mMovers[i].update();
	}
}

void NOC_2_3_forces_many_realgravityApp::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
	gl::enableAlphaBlending();
	for( int i = 0; i < mMoverAmt; i++ ) {
		mMovers[i].display();
		mMovers[i].checkEdges();
	}
}

CINDER_APP_BASIC( NOC_2_3_forces_many_realgravityApp, RendererGl )
