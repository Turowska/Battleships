#ifndef SHIP_H
#define SHIP_H

#define BOOST_BIND_GLOBAL_PLACEHOLDERS

#include <vector>

#include <boost/python.hpp>

/**
	kontener przytrzymujący dane o statku: na których polach stoi statek, czy został zatopiony, jakiego jest rozmiaru
**/

struct Ship{
	public:
	Ship(std::vector<int> &fields);
	int getSize();
	bool getIsAfloat();
	void sunk();
	bool isInField(int number);	

	private:
	std::vector<int> body_;
	bool is_afloat_;
};

using namespace boost::python;

BOOST_PYTHON_MODULE(ship){
	class_<Ship>("Ship", init < std::vector<int> > ())
		.def("getSize", &Ship::getSize)
		.def("getIsAfloat", &Ship::getIsAfloat)
		.def("sunk", &Ship::sunk)
		.def("isInField", &Ship::isInField)
	;
}

#endif //SHIP_H
