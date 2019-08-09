#include "overlayButton.h"

overlayButton::overlayButton():ctype(CellType::blank),button_set(false) {
	img.loadImage(ctype2fname(ctype));
}

std::string overlayButton::ctype2fname(CellType c_type) {
	switch (c_type)
	{
	case CellType::blank:
		return "blank.jpg";
		break;
	case CellType::cross:
		return "cross.jpg";
		break;
	case CellType::circles:
		return "circle.jpg";
		break;
	default:
		return "blank.jpg";
		break;
	}
}

bool overlayButton::setCellType(CellType c_type) {
	bool res = false;
	if (!button_set) {
		img.loadImage(ctype2fname(c_type));
		ctype = c_type;
		button_set = true;
		res = true;
	}
	return res;
}

void overlayButton::overlayDraw() {
		ofxButton::draw();
		auto point = ofxButton::getPosition();
		img.draw(point.x, point.y);
}

void overlayButton::clearButton() {
	ctype = CellType::blank;
	button_set = false;
	img.loadImage(ctype2fname(ctype));
}
