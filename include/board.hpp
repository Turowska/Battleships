#ifndef BOARD_H
#define BOARD_H

#include "field.hpp"
#include <array>

#include <boost/python.hpp>

/**
	kontener przechowujący 100 kontenerów klasy Field
**/

class Board{
	public:
	Board(std::array<bool, 100> fields);
	bool getIsOccupied(int number);
	bool getIsHit(int number);
	bool shot(int number);
	

	private:
	std::array<Field, 100> fields_;
};

#endif //BOARD_H
