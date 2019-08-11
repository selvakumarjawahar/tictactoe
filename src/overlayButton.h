#pragma once
#include "ofxButton.h"
#include "ofImage.h"
#include "commontypes.h"

#include <string>



class overlayButton :
	public ofxButton
{
public:
	overlayButton();
	bool setCellType(CellType c_type);
	void overlayDraw();
	void clearButton();

private:
	ofImage img;
	bool button_set;
	CellType ctype;
	std::string ctype2fname(CellType ctype);
};

