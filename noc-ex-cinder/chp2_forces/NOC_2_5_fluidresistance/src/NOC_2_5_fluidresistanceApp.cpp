//
//  Example 2-5: Fluid Resistance
//  The Nature of Code
//
//  Forces (Gravity and Fluid Resistence) with Vectors
//  by Daniel Shiffman.
//
//  Demonstration of multiple force acting on bodies (Mover class)
//  Bodies experience gravity continuously
//  Bodies experience fluid resistance when in "water"
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "cinder/Text.h"
#include "cinder/gl/Texture.h"
#include "Mover.h"
#include "Liquid.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_2_5_fluidresistanceApp : public AppBasic {
public:
	void prepareSettings( Settings *settings );
	void mouseDown( MouseEvent event );
	void setup();
	void update();
	void draw();
	void reset();
	
	vector<Mover>	mMovers;
	int				mMoverAmt = 11;
	Liquid			mLiquid;
	bool			mReady = false;
	gl::Texture		mText;
};

void NOC_2_5_fluidresistanceApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 800, 200 );
}

void NOC_2_5_fluidresistanceApp::setup()
{
	mMovers = vector<Mover>();
	for( int i = 0; i < mMoverAmt; i++ ){
		mMovers.push_back( Mover( randFloat( 1.0, 4.0 ), randFloat( getWindowWidth() ), 0.0 ) );
	}
	reset();
	
	mLiquid = Liquid( 0.0, getWindowHeight() / 2.0, getWindowWidth(), getWindowHeight()/2.0, 0.1 );
	
	TextLayout layout;
	layout.setColor( Color( 0.9f, 0.9f, 0.9f ) );
	layout.addCenteredLine( "click mouse to reset" );
	Surface8u rendered = layout.render( true, true );
	mText = gl::Texture( rendered );
}

void NOC_2_5_fluidresistanceApp::mouseDown( MouseEvent event)
{
	reset();
}

void NOC_2_5_fluidresistanceApp::update()
{
	for( int i = 0; i < mMovers.size(); i++ ) {
		
		// Is the Mover in the liquid?
		if( mLiquid.contains( mMovers[i] ) ) {
			// Calculate drag force
			Vec2f dragForce = mLiquid.drag(mMovers[i]);
			// Apply drag force to Mover
			mMovers[i].applyForce(dragForce);
		}
		
		 // Gravity is scaled by mass here!
		Vec2f gravity = Vec2f( 0, 0.1 * mMovers[i].mMass );
		// Apply gravity
		mMovers[i].applyForce( gravity );
		mMovers[i].update();
	}
	
}

void NOC_2_5_fluidresistanceApp::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
	gl::enableAlphaBlending();
	
	 // Draw water
	mLiquid.display();
	
	for( int i = 0; i < mMoverAmt; i++ ) {
		mMovers[i].display();
		mMovers[i].checkEdges();
	}
	
	gl::color( Color::black() );
	
	gl::draw(mText, Vec2f( 10.0, 10.0 ) );
}

void NOC_2_5_fluidresistanceApp::reset()
{
	console() << "reset" << endl;
	for (int i = 0; i < mMovers.size(); i++) {
		mMovers[i].reset( Vec2f( 40.0 + i * 70.0, 0 ) );
	}
}


CINDER_APP_BASIC( NOC_2_5_fluidresistanceApp, RendererGl )