#include "GamePlay.h"

GamePlay::GamePlay() :current_player{ Player::one }, game_updated{ false }, game_over{ false }{}
void GamePlay::update(TTTGrid& tttgrid) 
{
	if (game_updated) {
		game_updated = false;
		if (checkWinner(player1)) {
			std::cout << "Winner is Player 1" << '\n';
			return;
		}
		if (checkWinner(player2)) {
			std::cout << "Winner is Player 2" << '\n';
			return;
		}
	}
	return;
}
void GamePlay::handleClick(int x_pos, int y_pos,TTTGrid& tttgrid)
{
	if (!game_over)
	{
		CellType set_cell = current_player == Player::one ? CellType::cross : CellType::circles;
		auto cell_index = tttgrid.getCell(x_pos, y_pos);
		auto did_set = tttgrid.setCell(set_cell, cell_index);
		if (did_set) {
			if (current_player == Player::one) {
				player1.append(std::to_string(cell_index));
			}
			else {
				player2.append(std::to_string(cell_index));
			}
			togglePlayer();
		}
		game_updated = true;
	}
}
void GamePlay::togglePlayer()
{
	current_player = current_player == Player::one ? Player::two : Player::one;
}
bool GamePlay::checkWinner(std::string player) {
	bool res = false;
	for (auto str : win_patterns) {
		auto pos = player.find(str);
		if (pos != std::string::npos) {
			res = true;
			game_over = true;
			break;
		}
	}
	return res;
}