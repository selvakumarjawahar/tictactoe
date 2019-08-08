#pragma once
#include "TTTGrid.h"
#include "overlayButton.h"
#include <string>
#include <vector>

enum Player {one,two};
enum PlayerType{human,ai};
struct WinningCombo {
	int in1;
	int in2;
	int in3;
};

class GamePlay {
public:
	GamePlay();
	void handleClick(int x_pos, int y_pos,TTTGrid& tttgrid);
	void update(TTTGrid& tttgrid);
private:
	Player current_player;
	const std::vector<WinningCombo> winning_list{ {0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6} };
	std::vector<int> player1_moves;
	std::vector<int> player2_moves;
	bool game_updated;
	bool game_over;
	void togglePlayer();
	bool checkWinner(std::vector<int>& player_moves);
};