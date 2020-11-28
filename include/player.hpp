#ifndef PLAYER_H
#define PLAYER_H

#define BOOST_BIND_GLOBAL_PLACEHOLDERS

#include "board.hpp"
#include "ship.hpp"
#include <utility>
#include <vector>

#include <boost/python.hpp>

class Player{
	public:
	Player(std::array<bool, 100> fields);
	bool shot(int number);
	bool getIsSunk(int number);
	bool endGame();

	private:
	Board board_;
	std::vector<Ship> ships_;

	void sunk(int number);
};

using namespace boost::python;

BOOST_PYTHON_MODULE(player){
	class_<Player>("Player", init < std::array<bool, 100> > ())
		.def("getIsSunk", &Player::getIsSunk)
		.def("shot", &Player::shot)
		.def("endGame", &Player::endGame)
	;
}

#endif //PLAYER_H
