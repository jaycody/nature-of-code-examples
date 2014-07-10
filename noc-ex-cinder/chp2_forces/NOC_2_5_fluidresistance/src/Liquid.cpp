//
//  Liquid.cpp
//  NOC_2_5_fluidresistance
//
//  Created by Greg Kepler on 11/19/12.
//
//

#include "cinder/app/AppBasic.h"
#include "Liquid.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Liquid::Liquid()
{
	
}

Liquid::Liquid( float x, float y , float w, float h, float c )
	: mX( x ), mY( y ), mW( w ), mH( h ), mC( c )
{
	
}


// Is the Mover in the Liquid?
bool Liquid::contains( const Mover &m )
{
	Vec2f l = m.mLocation;
    if ( l.x > mX && l.x < mX + mW && l.y > mY && l.y < mY + mH ) {
		return true;
    }
    else {
		return false;
    }
}


// Calculate drag force
Vec2f Liquid::drag( const Mover &m ) {
    // Magnitude is coefficient * speed squared
    float speed = m.mVelocity.length();
    float dragMagnitude = mC * speed * speed;
	
    // Direction is inverse of velocity
    Vec2f dragForce = Vec2f( m.mVelocity );
    dragForce *= -1;
    
    // Scale according to magnitude
    // dragForce.setMag(dragMagnitude);
    dragForce.normalize();
    dragForce *= dragMagnitude;
    return dragForce;
}

void Liquid::display() {
	gl::color( Color8u::gray( 50 ) );
	gl::drawSolidRect( Rectf( mX, mY, mW, mY + mH ) );
}
