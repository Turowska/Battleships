//#define BOOST_BIND_GLOBAL_PLACEHOLDERS
#include "game.h"

#include <iostream>

//#include <boost/python.hpp>

Game::Game(const std::array<bool, 100>& firstPlayersBoard,
           const std::array<bool, 100>& secondPlayersBoard)
    : round_(true),
      players_(Player(firstPlayersBoard), Player(secondPlayersBoard)) {}

void Game::NextRound() { round_ = !round_; }

bool Game::Shot(int number) {
  if (round_) {
    return players_.second.Shot(number);
  }
  return players_.first.Shot(number);
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
/*
using namespace boost::python;

BOOST_PYTHON_MODULE(libgame) {
  class_<Game>("Game", init<std::array<bool, 100>, std::array<bool, 100> >())
      .def("IsSunk", &Game::IsSunk)
      .def("Shot", &Game::Shot)
      .def("IsEnd", &Game::IsEnd)
      .def("NextRound", &Game::NextRound);
}*/
