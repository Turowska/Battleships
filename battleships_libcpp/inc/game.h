#ifndef BATTLESHIPS_LIBCPP_INC_GAME_H_
#define BATTLESHIPS_LIBCPP_INC_GAME_H_

#define BOOST_BIND_GLOBAL_PLACEHOLDERS

#include <array>
#include <boost/python.hpp>
#include <utility>

#include "inc/player.h"

class Game {
 public:
  Game(const std::array<bool, 100>& firstPlayersBoard,
       const std::array<bool, 100>& secondPlayersBoard);
  void NextRound();
  bool Shot(int number);
  bool IsSunk(int number) const;
  bool IsEnd() const;

 private:
  bool round_;
  std::pair<Player, Player> players_;
};

using namespace boost::python;

BOOST_PYTHON_MODULE(game) {
  class_<Game>("Game", init<std::array<bool, 100>, std::array<bool, 100> >())
      .def("IsSunk", &Game::IsSunk)
      .def("Shot", &Game::Shot)
      .def("IsEnd", &Game::IsEnd)
      .def("NextRound", &Game::NextRound);
}

#endif  // BATTLESHIPS_LIBCPP_INC_GAME_H_
