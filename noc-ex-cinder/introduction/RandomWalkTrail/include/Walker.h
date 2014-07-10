//
//  Walker.h
//  Random Walk Trail
//  The Nature of Code
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppBasic.h"

class Walker
{
public:
	Walker();
	void display();
	void walk();
	
private:
	cinder::Vec2f				mLoc;
	std::list<cinder::Vec2f>	mHistory;
};
