#include "board.hpp"

Board::Board(std::array<bool, 100> fields){
	std::array<Field, 100>::iterator j = fields_.begin();
	for(std::array<bool, 100>::iterator i = fields.begin();  i != fields.end() && j != fields_.end(); ++i, ++j){
		(*j).setIsOccupied(*i);
	}
}

bool Board::getIsOccupied(int number){
	return fields_[number].getIsOccupied();
}

bool Board::getIsHit(int number){
	return fields_[number].getIsHit();
}

bool Board::shot(int number){
	return fields_[number].shotField();
}
