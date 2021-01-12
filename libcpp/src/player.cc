#include "player.h"

#include <iostream>

Player::Player(const std::array<bool, 100>& fields) : board_(fields), isGood_(true) {
    int count = 0;
    for (int i = 0; i < 100; ++i) {
	if (fields[i] && (i<10 || !fields[i-10]) &&
        (i%10==0 || !fields[i-1])) {
	    if ((i<90 && i%10!=0 && fields[i+9])||(i<90 && i%10!=9 && fields[i+11])||(i<90 && i%10!=9 && fields[i+1] && fields[i+10])) {
		isGood_ = false;
		return;
	    }
	    std::vector<int> ship;
	    ++count;
	    ship.push_back(i);
	    for (int j = i+1; j%10!=0 && fields[j]; ++j) {
		if (j<90 && j%10!=9 && fields[j+11]) {
		    isGood_ = false;
		    return;
	        }
		++count;
		ship.push_back(j);
	    }
	    for (int j = i+10; j<100 && fields[j]; j += 10) {
		if ((j<90 && j%10!=0 && fields[j+9])||(j<90 && j%10!=9 && fields[j+11])) {
		    isGood_ = false;
		    return;
	        }
		++count;
		ship.push_back(j);
	    }
	    ships_.push_back(Ship(ship));
	}
    }
    if(count!=COUNT_OCCUPIED_FIELDS||ships_.size()!=COUNT_SHIPS){
	isGood_ = false;
    }
}

bool Player::Shot(int number) {
    if (!(board_.Shot(number))) {
	return false;
    }
    int i = number - 1;
    while (i % 10 != 9 && i != -1 && board_.GetIsOccupied(i)) {
	if (!board_.GetIsHit(i)) {
	    return true;
	}
	--i;
    }

    i = number + 1;
    while (i % 10 != 0 && board_.GetIsOccupied(i)) {
	if (!board_.GetIsHit(i)) {
	    return true;
	}
	++i;
    }

    i = number - 10;
    while (i >= 0 && board_.GetIsOccupied(i)) {
	if (!board_.GetIsHit(i)) {
	    return true;
	}
	i -= 10;
    }
    i = number + 10;
    while (i < 100 && board_.GetIsOccupied(i)) {
	if (!board_.GetIsHit(i)) {
	    return true;
	}
	i += 10;
    }
    Sunk(number);
    return true;
}

void Player::Sunk(int number) {
    for (auto i = ships_.begin(); i != ships_.end(); ++i) {
	if ((*i).IsInField(number)) {
	    (*i).Sunk();
	}
    }
}

std::vector<int> Player::GetIsSunk(int number) {
    for (auto i = ships_.begin(); i != ships_.end(); ++i) {
	if ((*i).IsInField(number) && (*i).GetIsAfloat()) {
	    return (*i).GetIndex();
	}
    }
    std::vector<int> empty;
    return empty;
}

bool Player::EndGame() {
    for (auto i = ships_.begin(); i != ships_.end(); ++i) {
	if (!(*i).GetIsAfloat()) {
	    return false;
	}
    }
    return true;
}

bool Player::IsGood() {
    return isGood_;
}
