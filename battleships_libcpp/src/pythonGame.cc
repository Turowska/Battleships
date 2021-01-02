#define BOOST_BIND_GLOBAL_PLACEHOLDERS
#include "game.h"
#include <boost/python.hpp>
#include <iostream>

using namespace boost::python;

class PythonGame{
public:
	PythonGame(list tabListFirstPlayer, list tabListSecondPlayer){
		if(len(tabListFirstPlayer)!=100||len(tabListSecondPlayer)!=100){
			std::cout<<"zamale tablice\n";
			return;
		}
		std::array<bool, 100> tabArrayFirstPlayer;
		std::array<bool, 100> tabArraySecondPlayer;
		for(int i = 0; i < 100; ++i){
			tabArrayFirstPlayer[i] = extract<bool>(tabListFirstPlayer[i]);
			tabArraySecondPlayer[i] = extract<bool>(tabListSecondPlayer[i]);
		} 
		game_ = new Game(tabArrayFirstPlayer, tabArraySecondPlayer);
	}

	void NextRound(){
		game_->NextRound();
	}
	bool Shot(int number){
		return game_->Shot(number);
	}
	bool IsSunk(int number){
		return game_->IsSunk(number);
	}
	bool IsEnd(){
		if(game_->IsEnd()){
			delete game_;
			return true;
		}
		return false;
	}

private:
	
	Game* game_;

};

BOOST_PYTHON_MODULE(libpythonGame) {
  class_<PythonGame>("Game", init< list, list >())
      .def("IsSunk", &PythonGame::IsSunk)
      .def("Shot", &PythonGame::Shot)
      .def("IsEnd", &PythonGame::IsEnd)
      .def("NextRound", &PythonGame::NextRound);
}

