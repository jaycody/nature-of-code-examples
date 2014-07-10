//
//  Example 5-3: Chain Shape Simple
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//
//  An uneven surface
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include <Box2D/Box2D.h>
#include "Particle.h"
#include "Surface.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_5_03_ChainShape_SimpleApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	
	b2World*			mWorld;
    vector<Particle*>	mParticles;
	SurfaceBoundary*	mSurface;
};

void NOC_5_03_ChainShape_SimpleApp::prepareSettings( Settings *settings )
{
    settings->setWindowSize( 640, 360 );
}

void NOC_5_03_ChainShape_SimpleApp::setup()
{
	b2Vec2 gravity( 0.0f, 10.0f );
    mWorld = new b2World( gravity );
	mSurface = new SurfaceBoundary( mWorld );
}

void NOC_5_03_ChainShape_SimpleApp::mouseDown( MouseEvent event )
{
}

void NOC_5_03_ChainShape_SimpleApp::update()
{
	for( int i = 0; i < 5; ++i )
		mWorld->Step( 1 / 30.0f, 10, 10 );
}

void NOC_5_03_ChainShape_SimpleApp::draw()
{
	gl::clear( Color::white() );
	
	// If the mouse is pressed, we make new particles
	if ( randFloat() < 0.5 ) {
		float sz = randFloat( 4, 8 );
		mParticles.push_back( new Particle( mWorld, Vec2f( getWindowWidth() / 2, 10.0 ), sz ) );
	}
	
	// Draw the surface
	mSurface->display();
	
	// Draw all particles
	for( vector<Particle*>::iterator p = mParticles.begin(); p != mParticles.end(); ++p ) {
		(*p)->display();
	}
	
	if(mParticles.size() > 0){
		for( vector<Particle*>::iterator p = mParticles.end()-1; p != mParticles.begin(); --p ) {
			if ((*p)->done()) {
				mParticles.erase( p );
			}
		}
	}

}

CINDER_APP_NATIVE( NOC_5_03_ChainShape_SimpleApp, RendererGl )
