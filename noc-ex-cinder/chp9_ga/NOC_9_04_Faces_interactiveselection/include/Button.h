//
//  Button.h
//
//  Created by Greg Kepler
//
//

#include "Cinder/app/AppNative.h"

class Button {
	
	public:
	Button( int x, int y, int w, int h, std::string s );
	
	void			display();
	bool			rollover( ci::Vec2f mousePos );
	bool			clicked( ci::Vec2f mousePos );
	bool			released();
	
	ci::Rectf		mRect;			// Button's rectangle
	std::string		mTxt;			// Button's text
	bool			mClickedOn;		// Did i click on it?
	bool			mRolloverOn;	// Did i rollover it?
	
};