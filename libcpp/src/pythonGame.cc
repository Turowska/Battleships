#define BOOST_BIND_GLOBAL_PLACEHOLDERS
#include "pythonGame.h"
#include <boost/python.hpp>
#include <iostream>

using namespace boost::python;

PythonGame::PythonGame(list tabListFirstPlayer, list tabListSecondPlayer): isGood_(true) {
    if(len(tabListFirstPlayer)!=ROWS*COLUMNS||len(tabListSecondPlayer)!=ROWS*COLUMNS){
	isGood_ = false;
    } else {
	std::array<bool, ROWS*COLUMNS> tabArrayFirstPlayer;
	std::array<bool, ROWS*COLUMNS> tabArraySecondPlayer;
	for(int i = 0; i < ROWS*COLUMNS; ++i){
	    tabArrayFirstPlayer[i] = extract<bool>(tabListFirstPlayer[i]);
	    tabArraySecondPlayer[i] = extract<bool>(tabListSecondPlayer[i]);
	} 
	game_ = new Game(tabArrayFirstPlayer, tabArraySecondPlayer);
    }
}

bool PythonGame::Shot(int number, int player) {
    return game_->Shot(number, player);
}

list PythonGame::IsSunk(int number) {
    list numbers;
    std::vector<int> wsk(game_->IsSunk(number));
    for(unsigned int i=0; i<wsk.size(); ++i) {
	numbers.append(wsk[i]);
    } 
    return numbers;
}

bool PythonGame::IsEnd() {
    if(game_->IsEnd()){
	delete game_;
	return true;
    }
    return false;
}

bool PythonGame::IsGood() {
    if(isGood_) {
	isGood_ = game_->IsGood();
    }
    return isGood_;
}


BOOST_PYTHON_MODULE(pythonGame)
{
	class_<PythonGame>("Game", init<list, list>())
			.def("IsSunk", &PythonGame::IsSunk)
			.def("Shot", &PythonGame::Shot)
			.def("IsEnd", &PythonGame::IsEnd)
			.def("IsGood", &PythonGame::IsGood);
}
