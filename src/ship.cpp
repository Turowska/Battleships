#include "ship.hpp"

Ship::Ship(std::vector<int> &fields): is_afloat_(false) {
	body_ = fields;
}

int Ship::getSize(){
	return body_.size();
}

bool Ship::getIsAfloat(){
	return is_afloat_;
}

void Ship::sunk(){
	is_afloat_ = true;
}

bool Ship::isInField(int number){
	for(std::vector<int>::iterator i = body_.begin(); i != body_.end(); ++i){
		if((*i) == number){
			return true;
		}
	}
	return false;
}
