#ifndef BATTLESHIPS_LIBCPP_INC_PLAYER_H_
#define BATTLESHIPS_LIBCPP_INC_PLAYER_H_

#define BOOST_BIND_GLOBAL_PLACEHOLDERS

//#include <boost/python.hpp>
#include <utility>
#include <vector>

#include "board.h"
#include "ship.h"

class Player {
 public:
  explicit Player(const std::array<bool, 100>& fields);
  bool Shot(int number);
  bool GetIsSunk(int number);
  bool EndGame();

 private:
  Board board_;
  std::vector<Ship> ships_;

  void Sunk(int number);
};
/*
using namespace boost::python;

BOOST_PYTHON_MODULE(player) {
  class_<Player>("Player", init<std::array<bool, 100> >())
      .def("GetIsSunk", &Player::GetIsSunk)
      .def("Shot", &Player::Shot)
      .def("EndGame", &Player::EndGame);
}
*/
#endif  // BATTLESHIPS_LIBCPP_INC_PLAYER_H_
