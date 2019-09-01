#pragma once
#include "commontypes.h"
#include "GameStateMap.h"

#include <vector>
#include <algorithm>
#include <optional>
#include <iterator>
#include <random>
#include <utility>
#include <cassert>
#include <boost/optional.hpp>

class AIEngine {
public:
	AIEngine(CellType x_o,double state_value_default,double learning_rate, double draw_state_value,int exploratory_count);
	boost::optional<int> getMove(const GameState& current_st);
	void resetGame();
private:
	const CellType x_o;
	GameStateMap state_map;
	const double state_value_default;
	const double learning_rate;
	const double draw_state_value;
	const int exploratory_count;
	int move_count;
	std::vector<GameState> recorded_moves;
	std::vector<GameState> generateValidStateList(const GameState& current_st);
	GameState chooseState(const std::vector<GameState>& valid_st_lst);
	boost::optional<int> getMoveIndex(const GameState& from_st, const GameState& to_st);
	int generateRandomIndex(int max);
	double computeLearnedValue(double start_val, double end_val);
	void updateStateValue();
	std::vector<int> findVacantPos(const GameState& st);
	StateRecordList findHighestValueStates(const std::vector<GameState>& state_lst);
};
