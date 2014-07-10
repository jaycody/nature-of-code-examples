//
//  Boundary.cpp
//  NOC_5_02_Boxes
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNAtive.h"
#include "Boundary.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Boundary::Boundary( b2World* const world, ci::Vec2f pos, float w, float h, float a )
{
    mWorld = world;
    
    mPos = pos;
    mWidth = w;
    mHeight = h;
	mAngle = a;

    // Define the polygon
    b2PolygonShape ps;
    
    // We're just a box
    ps.SetAsBox( mWidth/2, mHeight/2 );
    
    
    // Create the body
    b2BodyDef bd;
    bd.type = b2_staticBody;
    bd.position.Set( mPos.x, mPos.y );
    mBody = mWorld->CreateBody( &bd );
    
    // Attached the shape to the body using a Fixture
    mBody->CreateFixture( &ps, 1 );
}

// Draw the boundary, if it were at an angle we'd have to do something fancier
void Boundary::display()
{
	float a = mBody->GetAngle();
	
	glPushMatrix();
	gl::translate( mPos.x, mPos.y );
	gl::rotate( -a );
	
	gl::color( Color::black() );
    gl::drawSolidRect( Rectf( -mWidth/2, -mHeight/2, -(mWidth/2) + mWidth, -(mHeight/2) + mHeight ) );
    glPopMatrix();
}

