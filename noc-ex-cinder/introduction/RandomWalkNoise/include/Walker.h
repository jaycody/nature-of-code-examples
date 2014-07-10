//
//  Walker.h
//  Random Walk Noise
//	The Nature of Code
//
//  Created by Greg Kepler
//
//

#import "cinder/Perlin.h"

class Walker
{
public:
	Walker();
	void render();
	void step();
	
private:
	float		mX, mY;
	float		mTx, mTy;
	float		mPrevX, mPrevY;
	ci::Perlin	mPerlin;
	bool		mReady;
};
