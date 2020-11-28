#ifndef FIELD_H
#define FIELD_H

#define BOOST_BIND_GLOBAL_PLACEHOLDERS

#include <boost/python.hpp>

/**
	kontener przechowujący informacje o zajętości pola i oddaniu strzału na dane pole
**/
class Field{
	public:
	Field();
	void setIsOccupied(bool is_occupied);
	bool getIsOccupied();
	bool getIsHit();
	bool shotField();

	private:
	bool is_occupied_;
	bool is_hit_;
};

using namespace boost::python;

BOOST_PYTHON_MODULE(field){
	class_<Field>("Field")
		.def("setIsOccupied", &Field::setIsOccupied)
		.def("getIsOccupied", &Field::getIsOccupied)
		.def("getIsHit", &Field::getIsHit)
		.def("shotField", &Field::shotField)
	;
}

#endif //FIELD_H
