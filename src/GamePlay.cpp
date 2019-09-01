#include "GamePlay.h"

GamePlay::GamePlay() :
	current_player{ Player::one },
	game_updated{ false },
	game_over{ false },
	player1_moves(9, 0),
	player2_moves(9, 0),
	ai_engine(CellType::cross, 0.5, 0.1, 0.0, 3) {}

void GamePlay::setup(TTTGrid& tttgrid) {
	makeAIMove(tttgrid);
	return;
}

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
		auto cell_index = tttgrid.getCell(x_pos, y_pos);
		makeHumanMove(cell_index, tttgrid);
		makeAIMove(tttgrid);
		game_updated = true;
	}
	return;
}

void GamePlay::resetGame() {
	current_player = Player::one;
	game_updated = false;
	game_over = false;
	player1_moves.swap(std::vector<int>(9, 0));
	player2_moves.swap(std::vector<int>(9, 0));
	std::swap(game_state, GameState{});
	ai_engine.resetGame();

}

void GamePlay::togglePlayer()
{
	current_player = current_player == Player::one ? Player::two : Player::one;
}

bool GamePlay::checkWinner(std::vector<int>& player_moves) {
	bool res = false;
	for (auto win_combo : WinningList) {
		res = player_moves[win_combo.in1] & player_moves[win_combo.in2] & player_moves[win_combo.in3];
		if (res) {
			game_over = true;
			break;
		}
	}
	return res;
}

void GamePlay::makeAIMove(TTTGrid& tttgrid) {
	auto move = ai_engine.getMove(game_state);
	if (move == boost::none) {
		std::cout << "Game Drawn \n";
		game_over = true;
		return;
	}
	auto did_set = tttgrid.setCell(CellType::cross, move.value());
	assert(did_set == true);
	player1_moves[move.value()] = 1;
	game_state.state[move.value()] = CellType::cross;
	return;
}

void GamePlay::makeHumanMove(int cell_index, TTTGrid& tttgrid) {
	auto did_set = tttgrid.setCell(CellType::circles, cell_index);
	if (did_set)
		player2_moves[cell_index] = 1;
	game_state.state[cell_index] = CellType::circles;
	return;
}
