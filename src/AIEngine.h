#pragma once
#include "commontypes.h"
#include <vector>
#include<algorithm>

class AIEngine {
public:
	AIEngine(CellType x_o,double state_value_default,double learning_rate,int exploratory_count);
	int getMove(const GameState& current_st);
	void resetGame();
private:
	CellType x_o;
	double state_value_default;
	double learning_rate;
	int exploratory_count;
	std::vector<GameState> game_states;
	std::vector<double> game_state_values;
	std::vector<GameState> state_tracker;
	void initGameStates();
	double getStateValue(const GameState& st);
	std::vector<GameState> generateValidStateList(const GameState& current_st);
	GameState chooseState(const std::vector<GameState>& valid_st_lst);
	int getMoveIndex(const GameState& from_st, const GameState& to_st);
	int generateRandomIndex(int max);
	double computeValue(double start_val, double end_val);
	void updateStateValue();
};