//
//  Walker.h
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
	float		mX, mY;
	bool		mReady;
};
