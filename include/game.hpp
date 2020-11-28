#ifndef GAME_H
#define GAME_H

#define BOOST_BIND_GLOBAL_PLACEHOLDERS

#include "player.hpp"
#include <utility>
#include <array>

#include <boost/python.hpp>

class Game{
	public:
	Game(std::array<bool, 100> firstPlayersBoard, std::array<bool, 100> secondPlayersBoard);
	void nextRound();
	bool shot(int number);
	bool isSunk(int number);
	bool isEnd();

	private:
	bool round_;
	std::pair<Player, Player> players_;
};

using namespace boost::python;

BOOST_PYTHON_MODULE(game){
	class_<Game>("Game", init < std::array<bool, 100>, std::array<bool, 100> > ())
		.def("isSunk", &Game::isSunk)
		.def("shot", &Game::shot)
		.def("isEnd", &Game::isEnd)
		.def("nextRound", &Game::nextRound)
	;
}


#endif //GAME_H
