#pragma once

#include "commontypes.h"
#include <vector>
#include <utility>
#include <boost/optional.hpp>

using StateValuePair = std::pair<GameState, double>;
struct StateRecord {
	int index;
	GameState state;
	double value;
};
using StateRecordList = std::vector<StateRecord>;
class GameStateMap {
public:
	explicit GameStateMap(const CellType x_o, const double default_state_value);
	int insertStateVal(StateValuePair stval);
	boost::optional<int> searchState(const GameState& st);
	StateRecord getRecord(const GameState& st);
	StateRecord getRecord(int index);
	StateRecordList getRecordList(const std::vector<GameState>& state_list);
private:
	std::vector<GameState> game_states;
	std::vector<double> game_state_values;
	const double default_state_value;
	void initStates(const CellType x_o);
};