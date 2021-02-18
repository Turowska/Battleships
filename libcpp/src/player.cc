#include "player.h"

#include <iostream>

Player::Player(const std::array<bool, ROWS*COLUMNS>& fields) : board_(fields), isGood_(true) {
    int count = 0;
    for (int i = 0; i < ROWS*COLUMNS; ++i) {
	if (fields[i] && (i<COLUMNS || !fields[i-COLUMNS]) &&
        (i%COLUMNS==0 || !fields[i-1])) {
	    if ((i<ROWS*COLUMNS-COLUMNS && i%COLUMNS!=0 && fields[i+COLUMNS-1])||(i<ROWS*COLUMNS-COLUMNS && i%COLUMNS!=COLUMNS-1 && fields[i+COLUMNS+1])||(i<ROWS*COLUMNS-COLUMNS && i%COLUMNS!=COLUMNS-1 && fields[i+1] && fields[i+COLUMNS])) {
		isGood_ = false;
		return;
	    }
	    std::vector<int> ship;
	    ++count;
	    ship.push_back(i);
	    for (int j = i+1; j%COLUMNS!=0 && fields[j]; ++j) {
		if (j<ROWS*COLUMNS-COLUMNS && j%COLUMNS!=COLUMNS-1 && fields[j+COLUMNS+1]) {
		    isGood_ = false;
		    return;
	        }
		++count;
		ship.push_back(j);
	    }
	    for (int j = i+COLUMNS; j<ROWS*COLUMNS && fields[j]; j += 10) {
		if ((j<ROWS*COLUMNS-COLUMNS && j%COLUMNS!=0 && fields[j+COLUMNS-1])||(j<ROWS*COLUMNS-COLUMNS && j%COLUMNS!=COLUMNS-1 && fields[j+COLUMNS+1])) {
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
    while (i % COLUMNS != COLUMNS-1 && i != -1 && board_.GetIsOccupied(i)) {
	if (!board_.GetIsHit(i)) {
	    return true;
	}
	--i;
    }

    i = number + 1;
    while (i % COLUMNS != 0 && board_.GetIsOccupied(i)) {
	if (!board_.GetIsHit(i)) {
	    return true;
	}
	++i;
    }

    i = number - COLUMNS;
    while (i >= 0 && board_.GetIsOccupied(i)) {
	if (!board_.GetIsHit(i)) {
	    return true;
	}
	i -= COLUMNS;
    }
    i = number + COLUMNS;
    while (i < ROWS*COLUMNS && board_.GetIsOccupied(i)) {
	if (!board_.GetIsHit(i)) {
	    return true;
	}
	i += COLUMNS;
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
