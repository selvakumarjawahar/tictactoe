#pragma once
#include "TTTGrid.h"
#include "overlayButton.h"
#include "commontypes.h"
#include "AIEngine.h"
#include "boost/optional.hpp"

#include <string>
#include <vector>
#include <cassert>

enum Player {one,two};

class GamePlay {
public:
	GamePlay();
	void setup(TTTGrid& tttgrid);
	void handleClick(int x_pos, int y_pos,TTTGrid& tttgrid);
	void update(TTTGrid& tttgrid);
	void resetGame();
private:
	Player current_player;
	std::vector<int> player1_moves;
	std::vector<int> player2_moves;
	GameState game_state;
	AIEngine ai_engine;
	bool game_updated;
	bool game_over;
	void makeAIMove(TTTGrid& tttgrid);
	void makeHumanMove(int cell_index, TTTGrid& tttgrid);
	void togglePlayer();
	bool checkWinner(std::vector<int>& player_moves);
};