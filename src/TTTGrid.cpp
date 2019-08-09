#include "TTTGrid.h"

void TTTGrid::setup() {
	ttt_grid.resize(9);
	for (int i = 0; i < 9; i++) {
		overlayButton b;
		ttt_grid.push_back(b);
	}
	ttt_grid[0].setShape(0, 0, 200, 200);
	ttt_grid[1].setShape(210, 0, 200, 200);
	ttt_grid[2].setShape(420, 0, 200, 200);
	ttt_grid[3].setShape(0, 210, 200, 200);
	ttt_grid[4].setShape(210, 210, 200, 200);
	ttt_grid[5].setShape(420, 210, 200, 200);
	ttt_grid[6].setShape(0, 420, 200, 200);
	ttt_grid[7].setShape(210, 420, 200, 200);
	ttt_grid[8].setShape(420, 420, 200, 200);

}

bool TTTGrid::setCell(CellType c_type, int index) {
	return ttt_grid[index].setCellType(c_type);
}


int TTTGrid::getCell(int xpos, int ypos) {
	int row = ypos / 200;
	int col = xpos / 200;
	return IndexLookUP[row][col];
}

void TTTGrid::clearGrid() {
	for (int index : {0, 1, 2, 3, 4, 5, 6, 7, 8}) {
		ttt_grid[index].clearButton();
	}
}

void TTTGrid::draw() {
	for (int index : {0, 1, 2, 3, 4, 5, 6, 7, 8}) {
		ttt_grid[index].overlayDraw();
		
	}
		
}