//
//  Particle
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "Particle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Particle::Particle()
{
	
}

Particle::Particle( ci::Vec2f location )
{
	// Fill all variables
	mAcceleration = Vec2f( 0.0, 0.05 );
    mVelocity = Vec2f( randFloat( -1, 1 ), randFloat( -1.0, 0.0 ) );
    mLocation = location;
    mLifespan = 255.0;
}

void Particle::run()
{
	update();
	display();
}

// Method to update location
void Particle::update()
{
	mVelocity += mAcceleration;
	mLocation += mVelocity;
	mLifespan -= 2.0;
	// we don't want the lifespan  to ever be negative
	if( mLifespan < 0.0 ) mLifespan = 0.0;
}

// Method to display
void Particle::display()
{
	gl::color( ColorA8u( 127, 127, 127, mLifespan ) );
	gl::drawSolidEllipse( mLocation, 6.0, 6.0 );
	
	gl::color( ColorA8u( 0, 0, 0, mLifespan ) );
	glLineWidth( 2.0 );
	gl::drawStrokedEllipse( mLocation, 6.0, 6.0 );
}

// Is the particle still useful?
bool Particle::isDead()
{
    if (mLifespan < 0.0) {
		return true;
    }
    else {
		return false;
    }
}