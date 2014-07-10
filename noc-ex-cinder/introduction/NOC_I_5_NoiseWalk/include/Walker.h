//
//  Walker.h
//  I.5 Noise Walk
//	The Nature of Code
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppBasic.h"
#import "cinder/Perlin.h"


class Walker
{
public:
	Walker();
	void walk();
	void display();
	
private:
	cinder::Vec2f	mLocation;
	cinder::Vec2f	mNOff;
	ci::Perlin		mPerlin;
	bool			mReady;
};
