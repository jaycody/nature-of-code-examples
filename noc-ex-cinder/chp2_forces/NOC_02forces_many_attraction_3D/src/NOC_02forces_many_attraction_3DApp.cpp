//
//  Forces: Many Attract - Repel 3D
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

class NOC_02forces_many_attraction_3DApp : public AppBasic {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	vector<Mover>	mMovers;
	int				mMoverAmt = 10;
	Attractor		mAttractor;
	float			mAngle;
};

void NOC_02forces_many_attraction_3DApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 800, 200 );
}

void NOC_02forces_many_attraction_3DApp::setup()
{
	mAngle = 0;
	mMovers = vector<Mover>();
	for( int i = 0; i < mMoverAmt; i++ )
	{
		mMovers.push_back( Mover( randFloat( 0.1, 2.0 ), randFloat( -getWindowWidth() / 2, getWindowWidth() / 2 ), randFloat( -getWindowHeight() / 2, getWindowHeight() / 2 ), randFloat( -100.0, 100 ) ) );
	}
	mAttractor = Attractor();
}

void NOC_02forces_many_attraction_3DApp::update()
{
	for( int i = 0; i < mMovers.size(); i++ )
	{
		Vec3f force = mAttractor.attract( mMovers[i] );
		mMovers[i].applyForce( force );
		mMovers[i].update();
	}
}

void NOC_02forces_many_attraction_3DApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
	gl::enableDepthRead();
	gl::enableDepthWrite();
	
	// -- lighting stuff --
	glEnable( GL_LIGHTING );
	glEnable( GL_LIGHT0 );
	// -- end lighting stuff --
	
	glPushMatrix();
	
	gl::translate( getWindowWidth() / 2, getWindowHeight() / 2 );
	gl::rotate( Vec3f(0, mAngle, 0 ) );
	
	gl::enableWireframe();
	mAttractor.display();
	gl::disableWireframe();
	
	for( int i = 0; i < mMovers.size(); i++ )
	{
		mMovers[i].display();
	}
	
	glPopMatrix();
	
	mAngle += toDegrees( 0.003 );
}

CINDER_APP_BASIC( NOC_02forces_many_attraction_3DApp, RendererGl )
