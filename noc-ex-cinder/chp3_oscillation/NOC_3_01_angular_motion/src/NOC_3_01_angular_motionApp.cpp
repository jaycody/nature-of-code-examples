//
//  Angular Motion
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_3_01_angular_motionApp : public AppBasic {
public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	float mAngle = 0.0;
	float mAVelocity = 0.0;
	float mAAcceleration = 0.0001;
};

void NOC_3_01_angular_motionApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 800, 200 );
}

void NOC_3_01_angular_motionApp::setup()
{
	gl::clear( Color( 1, 1, 1 ) );
}

void NOC_3_01_angular_motionApp::update()
{
	mAngle += mAVelocity;
	mAVelocity += mAAcceleration;
}

void NOC_3_01_angular_motionApp::draw()
{
	// no trail
	gl::clear( Color( 1, 1, 1 ) );
	
	// trail
	/*gl::enableAlphaBlending();
	gl::color( ColorA8u::gray( 255, 5 ) );
	gl::drawSolidRect( getWindowBounds() );*/
	
	
	glPushMatrix();
	gl::translate( getWindowCenter() );
	gl::rotate( toDegrees(mAngle) );
	glLineWidth( 2.0 );
	
	// line
	gl::color( Color::black() );
	gl::drawLine( Vec2f( -60.0, 0.0 ), Vec2f( 60.0 ,0. ) );
	
	// circle solids
	gl::color( Color8u::gray( 127 ) );
	gl::drawSolidEllipse( Vec2f( 60.0, 0.0 ), 8, 8 );
	gl::drawSolidEllipse( Vec2f( -60.0, 0.0 ), 8, 8 );
	
	// circle outlines
	gl::color( Color::black() );
	gl::drawStrokedEllipse( Vec2f( 60.0, 0.0 ), 8, 8 );
	gl::drawStrokedEllipse( Vec2f( -60.0, 0.0 ), 8, 8 );
	
	glPopMatrix();
}

CINDER_APP_BASIC( NOC_3_01_angular_motionApp, RendererGl )
