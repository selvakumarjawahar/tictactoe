#include "GameStateMap.h"

GameStateMap::GameStateMap(const CellType x_o, const double default_state_value):
	default_state_value(default_state_value) {
	initStates(x_o);
}

int GameStateMap::insertStateVal(StateValuePair st_val) {
	game_states.push_back(st_val.first);
	game_state_values.push_back(st_val.second);
	assert(game_states.size() == game_state_values.size());
	return game_states.size() - 1;
}

StateRecord GameStateMap::getRecord(const GameState& st) {
	double result_value = default_state_value;
	int result_index = 0;
	auto found = searchState(st);
	if (found != boost::none) {
		assert(found.value() < game_state_values.size());
		result_value = game_state_values[found.value()];
		result_index = found.value();
	}
	else {
		auto state = st;
		result_index = insertStateVal(std::make_pair(state, default_state_value));
	}
	return StateRecord{result_index,st,result_value};
}

StateRecord GameStateMap::getRecord(int index) {
	assert(game_states.size() == game_state_values.size());
	assert(index < game_states.size());
	return StateRecord{ index, game_states[index], game_state_values[index] };
}

StateRecordList GameStateMap::getRecordList(const std::vector<GameState>& state_list) {
	StateRecordList result;
	for (const auto& elem : state_list) 
		result.push_back(getRecord(elem));
	return result;
}

void GameStateMap::updateRecord(StateRecord record) {
	game_states[record.index] = record.state;
	game_state_values[record.index] = record.value;
}

boost::optional<int> GameStateMap::searchState(const GameState& st) {
	auto it = std::find(game_states.begin(), game_states.end(), st);
	if (it == game_states.end())
		return boost::none;
	return std::distance(game_states.begin(), it);
}

void GameStateMap::initStates(const CellType x_o) {
	for (auto& pattern : WinningList) {
		GameState st1, st2;
		st1.state[pattern.in1] = CellType::circles; st1.state[pattern.in2] = CellType::circles; st1.state[pattern.in3] = CellType::circles;
		st2.state[pattern.in1] = CellType::cross; st2.state[pattern.in2] = CellType::cross; st2.state[pattern.in3] = CellType::cross;
		game_states.push_back(st1);
		game_state_values.push_back(x_o == CellType::circles ? 1.0 : 0.0);
		game_states.push_back(st2);
		game_state_values.push_back(x_o == CellType::cross ? 1.0 : 0.0);
	}
	return;
}
