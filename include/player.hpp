#ifndef PLAYER_H
#define PLAYER_H

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

#endif //PLAYER_H
