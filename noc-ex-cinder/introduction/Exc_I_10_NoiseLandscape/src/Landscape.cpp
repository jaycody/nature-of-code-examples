//
//  Landscape.cpp
//  Exc_I_10_NoiseLandscape
//
//  Created by Greg Kepler on 11/5/12.
//
//

#include "cinder/app/AppBasic.h"
#include "cinder/CinderMath.h"
#include "cinder/Perlin.h"
#include "Landscape.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Landscape::Landscape(int scale, int width, int height)
{
	mScale = scale;
	mWidth = width;	
	mHeight = height;
	mCols = width/scale;
	mRows = height/scale;
	mPerlin = Perlin();
	mZOff = 0.0f;
	
	// adjust the size of the vectors now that we have the number of columns and rows
	mZ.resize( mCols );
	for( int i=0; i<mCols; i++ ){
		mZ[i].resize( mRows );
	}
}


void Landscape::calculate()
{
    float xoff = 0;
    for( int i = 0; i < mCols; i++ )
    {
		float yoff = 0;
		for( int j = 0; j < mRows; j++ )
		{
			mZ[i][j] = lmap( mPerlin.fBm( xoff, yoff, mZOff ) + 0.5f, 0.0f, 1.0f, -120.0f, 120.0f );
			yoff += 0.1;
		}
		xoff += 0.1;
    }
    mZOff += 0.01;
}

// Render landscape as grid of quads
void Landscape::render()
{
    // Every cell is an individual quad
    // (could use quad_strip here, but produces funny results, investigate this)
    for( int x = 0; x < mZ.size() - 1; x++ )
    {
		for( int y = 0; y < mZ[x].size() - 1; y++ )
		{
			
			// one quad at a time
			// each quad's color is determined by the height value at each vertex
			// (clean this part up)
			
			// There are more efficient ways to do this, but perhaps the easiest to explain
			
			glPushMatrix();
			gl::translate( Vec3f( ( x * mScale ) - ( mWidth / 2 ), ( y * mScale ) - ( mHeight / 2 ), -160 ) );
			
			// draw the quad
			gl::color( .6, .6, .6 );
			gl::begin( GL_QUADS );
			gl::vertex( 0, 0, mZ[x][y] );
			gl::vertex( mScale, 0, mZ[x+1][y] );
			gl::vertex( mScale, mScale, mZ[x+1][y+1] );
			gl::vertex( 0, mScale, mZ[x][y+1] );
			gl::end();
			
			// draw the outlines
			gl::color( 0, 0, 0 );
			gl::begin( GL_LINES );
			gl::vertex( 0, 0, mZ[x][y] );				// side 1
			gl::vertex( mScale, 0, mZ[x+1][y] );
			gl::vertex( mScale, 0, mZ[x+1][y] );		// side 2
			gl::vertex( mScale, mScale, mZ[x+1][y+1] );
			gl::vertex( mScale, mScale, mZ[x+1][y+1] );	// side 3
			gl::vertex( 0, mScale, mZ[x][y+1] );
			gl::vertex( 0, mScale, mZ[x][y+1] );		// line 4
			gl::vertex( 0, 0, mZ[x][y] );
			gl::end();
			
			glPopMatrix();
		}
    }
}