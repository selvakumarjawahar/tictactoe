#pragma once
#include "TTTGrid.h"
#include "overlayButton.h"
#include "commontypes.h"
#include "AIEngine.h"

#include <string>
#include <vector>

enum Player {one,two};

class GamePlay {
public:
	GamePlay();
	void setup();
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
	void makeAIMove();
	void togglePlayer();
	bool checkWinner(std::vector<int>& player_moves);
};