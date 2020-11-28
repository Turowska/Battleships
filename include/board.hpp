#ifndef BOARD_H
#define BOARD_H

#define BOOST_BIND_GLOBAL_PLACEHOLDERS

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

using namespace boost::python;

BOOST_PYTHON_MODULE(board){
	class_<Board>("Board", init < std::array<bool, 100> > ())
		.def("getIsOccupied", &Board::getIsOccupied)
		.def("getIsHit", &Board::getIsHit)
		.def("shot", &Board::shot)
	;
}

#endif //BOARD_H
