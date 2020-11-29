#ifndef BATTLESHIPS_LIBCPP_INC_FIELD_H_
#define BATTLESHIPS_LIBCPP_INC_FIELD_H_

#define BOOST_BIND_GLOBAL_PLACEHOLDERS

//#include <boost/python.hpp>

/**
        kontener przechowujący informacje o zajętości pola i oddaniu strzału na
dane pole
**/
class Field {
 public:
  Field();
  void SetIsOccupied(bool is_occupied);
  bool GetIsOccupied() const;
  bool GetIsHit() const;
  bool ShotField();

 private:
  bool is_occupied_;
  bool is_hit_;
};
/*
using namespace boost::python;

BOOST_PYTHON_MODULE(field) {
  class_<Field>("Field")
      .def("SetIsOccupied", &Field::SetIsOccupied)
      .def("GetIsOccupied", &Field::GetIsOccupied)
      .def("GetIsHit", &Field::GetIsHit)
      .def("ShotField", &Field::ShotField);
}
*/
#endif  // BATTLESHIPS_LIBCPP_INC_FIELD_H_
