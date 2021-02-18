//#define BOOST_BIND_GLOBAL_PLACEHOLDERS
#include "game.h"

#include <iostream>


Game::Game(const std::array<bool, ROWS*COLUMNS>& firstPlayersBoard,
           const std::array<bool, ROWS*COLUMNS>& secondPlayersBoard)
    : round_(true), isGood_(true),
      players_(Player(firstPlayersBoard), Player(secondPlayersBoard)) {
    if(!players_.first.IsGood()||!players_.second.IsGood()) {
	isGood_ = false;
    }
}

bool Game::Shot(int number, int player) {
    if(player==1){
	round_ = true;
	return players_.second.Shot(number);
    }else {
	round_ = false;
	return players_.first.Shot(number);
    }
}

std::vector<int> Game::IsSunk(int number) {
    if (round_) {
	return players_.second.GetIsSunk(number);
    }
    return players_.first.GetIsSunk(number);
}

bool Game::IsEnd() {
    return (players_.first.EndGame() || players_.second.EndGame());
}

bool Game::IsGood(){
    return isGood_;
}
