#include"AIEngine.h"
AIEngine::AIEngine(CellType x_o, double state_value_default, double learning_rate, int exploratory_count):
	x_o(x_o),state_value_default(state_value_default),learning_rate(learning_rate),exploratory_count(exploratory_count)
{
	initGameStates();

}
int AIEngine::getMove(const GameState& current_st) {
	auto st_lst = generateValidStateList(current_st);
	auto to_st = chooseState(st_lst);
	auto move_to = getMoveIndex(current_st, to_st);
	updateStateValue();
	return move_to;
}
void AIEngine::resetGame() {

}
void AIEngine::initGameStates() {
	return;
}
double AIEngine::getStateValue(const GameState& st) {
	return 0.0;
}
std::vector<GameState> AIEngine::generateValidStateList(const GameState& current_st) {
	return std::vector<GameState>{};
}
GameState AIEngine::chooseState(const std::vector<GameState>& valid_st_lst) {
	return GameState{};
}
int AIEngine::getMoveIndex(const GameState& from_st, const GameState& to_st) {
	return 0;
}
int AIEngine::generateRandomIndex(int max) {
	return 0;
}
double AIEngine::computeValue(double start_val, double end_val) {
	return 0.0;
}
void AIEngine::updateStateValue() {
	return;
}