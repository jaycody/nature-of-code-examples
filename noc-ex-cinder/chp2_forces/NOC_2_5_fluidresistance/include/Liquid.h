//
//  Liquid.h
//  NOC_2_5_fluidresistance
//
//  Created by Greg Kepler on 11/19/12.
//
//

#pragma once

#include "cinder/app/AppBasic.h"
#include "Mover.h"

class Liquid {
public:
	Liquid();
	Liquid( float x, float y , float w, float h, float c );
	
	float		mX, mY, mW, mH;		// Liquid is a rectangle
	float		mC;					// Coefficient of drag
	bool		contains( const Mover &m );
	ci::Vec2f	drag( const Mover &m );
	void		display();
};