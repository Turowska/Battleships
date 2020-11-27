#ifndef SHIP_H
#define SHIP_H

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

#endif //SHIP_H
