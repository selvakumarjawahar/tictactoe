#pragma once

#include"overlayButton.h"
#include"ofRectangle.h"
#include"commontypes.h"

#include<vector>
#include<map>
#include<string>


class TTTGrid {
public:
	TTTGrid();
	void setup();
	void draw();
	bool setCell(CellType c_type, int index);
	int getCell(int xpos, int ypos);
	void clearGrid();

private:
	std::vector<overlayButton> ttt_grid;

};

