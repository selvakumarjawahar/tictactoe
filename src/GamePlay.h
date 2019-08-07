#pragma once
#include "TTTGrid.h"
#include "overlayButton.h"
#include <string>
#include <vector>

enum Player {one,two};
enum PlayerType{human,ai};

class GamePlay {
public:
	GamePlay();
	void handleClick(int x_pos, int y_pos,TTTGrid& tttgrid);
	void update(TTTGrid& tttgrid);
private:
	Player current_player;
	const std::vector<std::string> win_patterns{ "012","345","678","036","147","258","048","246" };
	std::string player1;
	std::string player2;
	bool game_updated;
	bool game_over;
	void togglePlayer();
	bool checkWinner(std::string player);
};