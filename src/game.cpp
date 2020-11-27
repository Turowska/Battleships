#include "game.hpp"
#include <iostream>

Game::Game(std::array<bool, 100> firstPlayersBoard, std::array<bool, 100> secondPlayersBoard): round_(true), players_(Player(firstPlayersBoard), Player(secondPlayersBoard)) {}

void Game::nextRound(){
	round_ = !round_;
}

bool Game::shot(int number){
	if(round_){
		return players_.second.shot(number);
	}
	return players_.first.shot(number);
}

bool Game::isSunk(int number){
	if(round_){
		return players_.second.getIsSunk(number);
	}
	return players_.first.getIsSunk(number);
}

bool Game::isEnd(){
	return (players_.first.endGame()||players_.second.endGame());
}
