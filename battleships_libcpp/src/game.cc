#include "inc/game.h"

#include <iostream>

Game::Game(const std::array<bool, 100>& firstPlayersBoard,
           const std::array<bool, 100>& secondPlayersBoard)
    : round_(true),
      players_(Player(firstPlayersBoard), Player(secondPlayersBoard)) {}

void Game::NextRound() { round_ = !round_; }

bool Game::Shot(int number) {
  if (round_) {
    return players_.second.shot(number);
  }
  return players_.first.shot(number);
}

bool Game::IsSunk(int number) {
  if (round_) {
    return players_.second.GetIsSunk(number);
  }
  return players_.first.GetIsSunk(number);
}

bool Game::IsEnd() {
  return (players_.first.EndGame() || players_.second.EndGame());
}
