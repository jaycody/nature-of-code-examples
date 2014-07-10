//
//  Walker.h
//  Random Walk
//	The Nature of Code
//
//  Created by Greg Kepler
//
//

class Walker
{
public:
	Walker();
	void render();
	void step();
	
private:
	float	montecarlo();
	float	mX, mY;
	float	mPrevX, mPrevY;
	bool	mReady;
};
