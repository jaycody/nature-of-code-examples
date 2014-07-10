//
//  Landscape.h
//  Exc_I_10_NoiseLandscape
//
//  Created by Greg Kepler on 11/5/12.
//
//

#include "cinder/Perlin.h"

class Landscape
{
  public:
	Landscape(int scale, int width, int height);
	void calculate();
	void render();
	
  private:
	cinder::Perlin	mPerlin;
	int				mScale;					// size of each cell
	int				mWidth, mHeight;		// width and height of thingie
	int				mRows, mCols;			// number of rows and columns
	float			mZOff;					// perlin noise argument
	std::vector< std::vector<float> > mZ;	// instead of 2D array since you need to know the size at creation
	
};