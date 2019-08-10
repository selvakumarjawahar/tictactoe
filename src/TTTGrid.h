#pragma once

#include"overlayButton.h"
#include"ofRectangle.h"

#include<vector>
#include<map>
#include<string>

constexpr int IndexLookUP[3][3] = { {0,1,2},{3,4,5},{6,7,8} };

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

