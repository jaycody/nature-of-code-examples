//
//  Noise Distribution
//  The Nature of Code
//
//  Testing Distribution of Perlin Noise generated #'s vs. Randoms
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Perlin.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NoiseDistributionApp : public AppBasic {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	vector<float>	mVals;
	vector<float>	mNorms;
	float			mXOff;
	int				mWidth, mHeight;
	Perlin			mPerlin;
};

void NoiseDistributionApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 300, 200 );
}

void NoiseDistributionApp::setup()
{
	mXOff = 0.0f;
	mWidth = getWindowWidth();
	mHeight = getWindowHeight();
	mVals.resize( mWidth );
	mNorms.resize( mWidth );
	mPerlin = Perlin();
}

void NoiseDistributionApp::update()
{
}

void NoiseDistributionApp::draw()
{
	gl::clear( Color( 0.39, 0.39, 0.39 ) );
	
	float n = mPerlin.fBm( mXOff ) + .5;
	int index = int( n * mWidth );
	mVals[index]++;
	mXOff += 0.01;
	gl::color( 1, 1, 1 );
	bool normalization = false;
	float maxy = 0.0;
	for( int x = 0; x < mVals.size(); x++ ) {
		gl::drawLine( Vec2f( x, mHeight ), Vec2f( x, mHeight - mNorms[x] ) );
		if( mVals[x] > mHeight ) normalization = true;
		if( mVals[x] > maxy ) maxy = mVals[x];
	}
	for( int x = 0; x < mVals.size(); x++ ) {
		if( normalization ) mNorms[x] = ( mVals[x] / maxy ) * mHeight;
		else mNorms[x] = mVals[x];
	}
}

CINDER_APP_BASIC( NoiseDistributionApp, RendererGl )
