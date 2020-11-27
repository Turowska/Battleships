#include "field.hpp"

Field::Field(): is_occupied_(false), is_hit_(false) {}

void Field::setIsOccupied(bool is_occupied){
	is_occupied_ = is_occupied;
}

bool Field::getIsOccupied(){
	return is_occupied_;
}

bool Field::getIsHit(){
	return is_hit_;
}

bool Field::shotField(){
	is_hit_ = true;
	return is_occupied_;
}
