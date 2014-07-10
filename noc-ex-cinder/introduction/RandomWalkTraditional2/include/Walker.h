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
	int			mX, mY;
	bool		mReady;
};
