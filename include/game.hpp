#ifndef GAME_H
#define GAME_H

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

#endif //GAME_H
