//
//  Pendulum.h
//  NOC_3_10_PendulumExample
//
//  Created by Greg Kepler on 1/19/13.
//
//  A Simple Pendulum Class
//  Includes functionality for user can click and drag the pendulum
//

#include "cinder/app/AppBasic.h"

class Pendulum {
public:
	Pendulum();
	Pendulum( ci::Vec2f origin, float r );
	
	void clicked( ci::Vec2f mousePos );
	void update();
	void drag( ci::Vec2f mousePos );
	void stopDragging();
	void draw();
	
	
private:
	ci::Vec2f mLocation;	// Location of pendulum ball
	ci::Vec2f mOrigin;		// Location of arm origin
	float mRadius;			// Length of arm
	float mAngle;			// Pendulum arm angle
	float mAVelocity;		// Angle velocity
	float mAAcceleration;	// Angle acceleration
	
    float mBallr;			// Ball radius
	float mDamping;			// Arbitary damping amount
	
	bool mDragging = false;
};