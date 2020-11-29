#ifndef BATTLESHIPS_LIBCPP_INC_BOARD_H_
#define BATTLESHIPS_LIBCPP_INC_BOARD_H_

#define BOOST_BIND_GLOBAL_PLACEHOLDERS

#include <array>
//#include <boost/python.hpp>

#include "field.h"

/**
        kontener przechowujący 100 kontenerów klasy Field
**/

class Board {
 public:
  explicit Board(const std::array<bool, 100>& fields);
  bool GetIsOccupied(int number) const;
  bool GetIsHit(int number) const;
  bool Shot(int number);

 private:
  std::array<Field, 100> fields_;
};
/*
using namespace boost::python;

BOOST_PYTHON_MODULE(board) {
  class_<Board>("Board", init<std::array<bool, 100> >())
      .def("GetIsOccupied", &Board::GetIsOccupied)
      .def("GetIsHit", &Board::GetIsHit)
      .def("Shot", &Board::Shot);
}
*/
#endif  // BATTLESHIPS_LIBCPP_INC_BOARD_H_
