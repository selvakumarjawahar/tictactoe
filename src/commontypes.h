#pragma once
#include<array>
#include<vector>
#include<array>



enum CellType { blank, cross, circles };
constexpr int IndexLookUP[3][3] = { {0,1,2},{3,4,5},{6,7,8} };
struct GameState {
	std::array<CellType, 9> state;
	GameState() {
		state = { CellType::blank,CellType::blank,CellType::blank,CellType::blank,
			CellType::blank,CellType::blank,CellType::blank,CellType::blank };
	}
	bool operator == (const GameState& rhs) {
		return std::equal(this->state.begin(), this->state.end(), rhs.state.begin());
	}
};
struct WinningCombo {
	int in1;
	int in2;
	int in3;
};
const std::vector<WinningCombo> WinningList{ {0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6} };
