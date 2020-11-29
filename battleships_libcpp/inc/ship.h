#ifndef BATTLESHIPS_LIBCPP_INC_SHIP_H_
#define BATTLESHIPS_LIBCPP_INC_SHIP_H_

#define BOOST_BIND_GLOBAL_PLACEHOLDERS

//#include <boost/python.hpp>
#include <vector>

/**
        kontener przytrzymujący dane o statku: na których polach stoi statek,
czy został zatopiony, jakiego jest rozmiaru
**/

struct Ship {
 public:
  explicit Ship(const std::vector<int> &fields);
  int GetSize();
  bool GetIsAfloat();
  void Sunk();
  bool IsInField(int number);

 private:
  std::vector<int> body_;
  bool is_afloat_;
};
/*
using namespace boost::python;

BOOST_PYTHON_MODULE(ship) {
  class_<Ship>("Ship", init<std::vector<int> >())
      .def("GetSize", &Ship::GetSize)
      .def("GetIsAfloat", &Ship::GetIsAfloat)
      .def("Sunk", &Ship::Sunk)
      .def("IsInField", &Ship::IsInField);
}
*/
#endif  // BATTLESHIPS_LIBCPP_INC_SHIP_H_
