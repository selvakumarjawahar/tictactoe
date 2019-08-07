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

int TTTGrid::getCell(int xpos, int ypos) {
	int row = ypos / 200;
	int col = xpos / 200;
	//std::cout << "row = " << row << " col = " << col <<  " xpos =" << xpos << " ypos = " << ypos << '\n';
	switch (row)
	{
	case 0:
		switch (col)
		{
		case 0:
			return r0c0{}.value;
			break;
		case 1:
			return r0c1{}.value;
			break;
		case 2:
			return r0c2{}.value;
			break;
		default:
			break;
		}
	case 1:
		switch (col)
		{
		case 0:
			return r1c0{}.value;
			break;
		case 1:
			return r1c1{}.value;
			break;
		case 2:
			return r1c2{}.value;
			break;
		default:
			break;
		}
	case 2:
		switch (col)
		{
		case 0:
			return r2c0{}.value;
			break;
		case 1:
			return r2c1{}.value;
			break;
		case 2:
			return r2c2{}.value;
			break;
		default:
			break;
		}
	default:
		break;
	}
}

void TTTGrid::draw() {
	for (int index : {0, 1, 2, 3, 4, 5, 6, 7, 8}) {
		ttt_grid[index].overlayDraw();
		
	}
		
}