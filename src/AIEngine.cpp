#include"AIEngine.h"

AIEngine::AIEngine(CellType x_o, double state_value_default, double learning_rate, double draw_state_value, int exploratory_count):
	x_o(x_o),
	state_value_default(state_value_default),
	learning_rate(learning_rate),
	exploratory_count(exploratory_count),
	move_count(1),
	state_map(x_o,state_value_default),
	draw_state_value(draw_state_value) {}

boost::optional<int> AIEngine::getMove(const GameState& current_st) {
	updateStateValue();
	auto state_lst = generateValidStateList(current_st);
	if (state_lst.empty()) { //No More Moves its a Draw
		state_map.insertStateVal(std::make_pair(current_st, draw_state_value)); 
		return boost::none;
	}
	auto to_st = chooseState(state_lst);
	auto move_to = getMoveIndex(current_st, to_st);
	return move_to;
}

void AIEngine::resetGame() {
	recorded_moves.swap(std::vector<GameState>{});
	move_count = 1;
	assert(recorded_moves.size() == 0);
	return;
}

std::vector<GameState> AIEngine::generateValidStateList(const GameState& current_st) {
	auto vacant_pos = findVacantPos(current_st);
	std::vector<GameState> game_st;
	for (auto& elem : vacant_pos) {
		GameState st{ current_st };
		st.state[elem] = x_o;
		game_st.push_back(st);
	}
	return game_st;
}

GameState AIEngine::chooseState(const std::vector<GameState>& valid_st_lst) {
	move_count = move_count % exploratory_count;
	GameState result;
	if (move_count != 0) { //greedy move
		auto state_record_lst = findHighestValueStates(valid_st_lst);
		auto index = generateRandomIndex(state_record_lst.size() - 1);
		result = state_record_lst[index].state;
	}
	else { //exploratory move
		auto index = generateRandomIndex(valid_st_lst.size() - 1);
		auto record = state_map.getRecord(valid_st_lst[index]);
		result = record.state;
	}
	move_count++;
	recorded_moves.push_back(result);
	return result;
}

boost::optional<int> AIEngine::getMoveIndex(const GameState& from_st, const GameState& to_st) {
	boost::optional<int> result = boost::none;
    int index = 0;
	for (const auto& elem : from_st.state) {
		if (elem == to_st.state[index]) {
			result = index;
			break;
		}
		index++;
	}
	return result;
}

int AIEngine::generateRandomIndex(int max) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, max);
	return dis(gen);
}

double AIEngine::computeLearnedValue(double start_val, double end_val) {
	return start_val + ((end_val-start_val) * learning_rate);
}

void AIEngine::updateStateValue() {
	if(recorded_moves.size()<2)
		return;
	auto record_current = state_map.getRecord(*recorded_moves.rbegin());
	auto record_previous = state_map.getRecord(*(recorded_moves.rbegin() + 1));
	auto learned_value = computeLearnedValue(record_previous.value, record_current.value);
	state_map.updateRecord(StateRecord{ record_previous.index,record_previous.state,learned_value });
}

std::vector<int> AIEngine::findVacantPos(const GameState& st) {
	std::vector<int> results;
	for (auto& elem : {0,1,2,3,4,5,6,7,8}) {
		if (st.state[elem] == CellType::blank)
			results.push_back(elem);
	}
	return results;
}

StateRecordList AIEngine::findHighestValueStates(const std::vector<GameState>& state_lst) {
	auto record_list = state_map.getRecordList(state_lst);
	auto comparator = [](StateRecord const& elem1 , StateRecord const& elem2) {
		return elem1.value < elem2.value;
	};
	auto maxval = std::max_element(record_list.begin(),record_list.end(), comparator);
	StateRecordList result_list;
	for (auto elem : record_list) {
		if (elem.value == maxval->value)
			result_list.push_back(elem);
	}
	return result_list;
}

