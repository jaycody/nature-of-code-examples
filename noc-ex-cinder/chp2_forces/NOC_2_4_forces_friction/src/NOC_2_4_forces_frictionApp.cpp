//
//  Example 2-4: Forces Friction
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

class NOC_2_4_forces_frictionApp : public AppBasic {
public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	vector<Mover> mMovers;	// using a vector instead of an array
	int mMoverAmt = 5;
};

void NOC_2_4_forces_frictionApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 383, 200 );
}

void NOC_2_4_forces_frictionApp::setup()
{
	randSeed( 3 );
	
	mMovers = vector<Mover>();
	for( int i = 0; i < mMoverAmt; i++ ){
		mMovers.push_back( Mover( randFloat( 1.0, 4.0 ), randFloat( getWindowWidth() ), 0.0 ) );
	}
}

void NOC_2_4_forces_frictionApp::update()
{
	for( int i = 0; i < mMovers.size(); i++ ) {
		Vec2f wind = Vec2f( 0.01, 0.0 );
		Vec2f gravity = Vec2f( 0, 0.1 * mMovers[i].mMass );
		
		float c = 0.05;
		Vec2f friction = Vec2f( mMovers[i].mVelocity );
		if( friction != Vec2f( 0, 0 ) )
		{
			friction *= -1;
			friction.normalize();
			friction *= c;
		}
		
		mMovers[i].applyForce( friction );
		mMovers[i].applyForce( wind );
		mMovers[i].applyForce( gravity );
		mMovers[i].update();
	}
}

void NOC_2_4_forces_frictionApp::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
	gl::enableAlphaBlending();
	for( int i = 0; i < mMoverAmt; i++ ) {
		mMovers[i].display();
		mMovers[i].checkEdges();
	}
}


CINDER_APP_BASIC( NOC_2_4_forces_frictionApp, RendererGl )