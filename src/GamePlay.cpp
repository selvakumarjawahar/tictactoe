#include "GamePlay.h"

GamePlay::GamePlay() :current_player{ Player::one }, 
                      game_updated{ false }, 
	                  game_over{ false },  
	                  player1_moves( 9,0 ), 
	                  player2_moves( 9,0 )
                      {}

void GamePlay::update(TTTGrid& tttgrid) 
{
	if (game_updated) {
		game_updated = false;
		if (checkWinner(player1_moves)) {
			std::cout << "Winner is Player 1" << '\n';
			return;
		}
		if (checkWinner(player2_moves)) {
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
				player1_moves[cell_index] = 1; 
			}
			else {
				player2_moves[cell_index] = 1;
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
bool GamePlay::checkWinner(std::vector<int>& player_moves) {
	bool res = false;
	for (auto win_combo : winning_list) {
		res = player_moves[win_combo.in1] & player_moves[win_combo.in2] & player_moves[win_combo.in3];
		if (res) {
			game_over = true;
			break;
		}
			
	}
	return res;
}