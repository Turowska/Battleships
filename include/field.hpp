#ifndef FIELD_H
#define FIELD_H

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



#endif //FIELD_H
