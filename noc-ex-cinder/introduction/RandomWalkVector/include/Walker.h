//
//  Walker.h
//  Random Walk Vectors
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
	void render();
	void walk();
	
private:
	cinder::Vec2f mLoc;
};
