#include "player.hpp"
#include <iostream>

Player::Player(std::array<bool, 100> fields): board_(fields) {
	for(int i=0; i<100; ++i){
		if(fields[i]&&(i<10||!fields[i-10])&&(i%10==0||!fields[i-1])){
			std::vector<int> ship;
			ship.push_back(i);
			for(int j=i+1; j%10!=0&&fields[j]; ++j){
				ship.push_back(j);
			}
			for(int j=i+10; j<100&&fields[j]; j+=10){
				ship.push_back(j);
			}
			ships_.push_back(Ship(ship));
		}
	}
}

bool Player::shot(int number){
	if(!(board_.shot(number))){
		return false;
	}
	int i = number-1;
	while(i%10!=9&&i!=-1&&board_.getIsOccupied(i)){
		if(!board_.getIsHit(i)){
			return true;
		}
		--i;
	}

	i = number+1;
	while(i%10!=0&&board_.getIsOccupied(i)){
		if(!board_.getIsHit(i)){
			return true;
		}
		++i;
	}
	
	i = number-10;
	while(i>=0&&board_.getIsOccupied(i)){
		if(!board_.getIsHit(i)){
			return true;
		}
		i -= 10;
	}
	i = number+10;
	while(i<100&&board_.getIsOccupied(i)){
		if(!board_.getIsHit(i)){
			return true;
		}
		i += 10;
	}
	sunk(number);
	return true;
}

void Player::sunk(int number){
	for(std::vector<Ship>::iterator i = ships_.begin(); i != ships_.end(); ++i){
		if((*i).isInField(number)){
			(*i).sunk();
		}
	}
}

bool Player::getIsSunk(int number){
	for(std::vector<Ship>::iterator i = ships_.begin(); i != ships_.end(); ++i){
		if((*i).isInField(number)){
			return (*i).getIsAfloat();
		}
	}
	return false;
}

bool Player::endGame(){
	for(std::vector<Ship>::iterator i = ships_.begin(); i != ships_.end(); ++i){
		if(!(*i).getIsAfloat()){
			return false;
		}
	}
	return true;
}
