//
//  Oscillator.h
//  NOC_3_07_oscillating_objects
//
//  Created by Greg Kepler on 1/6/13.
//
//

#include "cinder/app/AppBasic.h"

class Oscillator {
  public:
	Oscillator();
	Oscillator( ci::Vec2f windowSize );
	
	void oscillate();
	void display();
	
  private:
	ci::Vec2f	mAngle, mVelocity, mAmplitude;
};