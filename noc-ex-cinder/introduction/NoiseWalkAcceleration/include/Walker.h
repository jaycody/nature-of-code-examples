//
//  Walker.h
//  Noise Walk Acceleration
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
	cinder::Vec2f	mLocation, mVelocity, mAcceleration;
	std::list<cinder::Vec2f> mHistory;
	cinder::Vec2f	mNOff;
	ci::Perlin		mPerlin;
	bool			mReady;
};
