#define BOOST_BIND_GLOBAL_PLACEHOLDERS
#include "game.h"
#include <boost/python.hpp>

using namespace boost::python;

BOOST_PYTHON_MODULE(libpythonGame) {
  class_<Game>("Game", init<std::array<bool, 100>, std::array<bool, 100> >())
      .def("IsSunk", &Game::IsSunk)
      .def("Shot", &Game::Shot)
      .def("IsEnd", &Game::IsEnd)
      .def("NextRound", &Game::NextRound);
}

