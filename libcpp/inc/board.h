#ifndef BATTLESHIPS_LIBCPP_INC_BOARD_H_
#define BATTLESHIPS_LIBCPP_INC_BOARD_H_

#include <array>
#include "field.h"

#define ROWS 10
#define COLUMNS 10

/**
* @brief presents the player's board
*
* stores 100 Field objects
*/
class Board {

    public:
	/**
	* @brief creates board and sets ships by array
	*
	* the occupation of a given field is set to the value of the field in a given array
	* @param fields board with the arrangement of ships
	*/
	Board(const std::array<bool, ROWS*COLUMNS>& fields);
	/**
	* @brief checks the occupation of the field with the given index
	*
	* @param number index of the field
	* @return field occupancy (true - the field is occupied; false - the field is unoccupied)
	*/
	bool GetIsOccupied(int number) const;
	/**
	* @brief checks if the field with the given index has been checked
	*
	* @param number index of the field
	* @return true - the field has been checked; false - the field has not been checked yet
	*/
	bool GetIsHit(int number) const;
	/**
	* @brief taking a shot
	*
	* sets the field with the given index as checked and checks its occupation
	* @param number index of the field
	* @return field occupancy (true - the field is occupied; false - the field is unoccupied)
	*/
	bool Shot(int number);

    private:
	/**
	* array of field
	*/
	std::array<Field, ROWS*COLUMNS> fields_;
};

#endif  // BATTLESHIPS_LIBCPP_INC_BOARD_H_
