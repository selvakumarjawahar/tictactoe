#pragma once
#include<array>
#include<vector>

enum CellType { blank, cross, circles };
constexpr int IndexLookUP[3][3] = { {0,1,2},{3,4,5},{6,7,8} };
using GameState = std::array<CellType,9>;
struct WinningCombo {
	int in1;
	int in2;
	int in3;
};
const std::vector<WinningCombo> WinningList{ {0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6} };
