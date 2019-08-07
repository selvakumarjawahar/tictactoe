#pragma once

#include"overlayButton.h"
#include"ofRectangle.h"

#include<vector>
#include<map>
#include<string>

struct cell{};
struct r0c0 :public cell { int value = 0; }; struct r0c1 :public cell { int value = 1; }; struct r0c2 :public cell { int value = 2; };
struct r1c0 :public cell { int value = 3; };struct r1c1 :public cell { int value = 4; }; struct r1c2 :public cell { int value = 5; };
struct r2c0 :public cell { int value = 6; }; struct r2c1 :public cell { int value = 7; }; struct r2c2 :public cell { int value = 8; };

class TTTGrid {
public:
	void setup();
	void draw();
	template<typename T>
	bool setCell(CellType c_type) {
		return ttt_grid[getIndex<T>()].setCellType(c_type);
	}
	bool setCell(CellType c_type,int index) {
		return ttt_grid[index].setCellType(c_type);
	}
	int getCell(int xpos, int ypos);

private:
	std::vector<overlayButton> ttt_grid;
	template<typename T>
	int getIndex() {
		T obj;
		return obj.value;
	}

};

