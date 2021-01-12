#ifndef BATTLESHIPS_LIBCPP_INC_SHIP_H_
#define BATTLESHIPS_LIBCPP_INC_SHIP_H_

#include <vector>

/**
* @brief presents a ship
*
* stores information about the ship: size, position, state
*/
class Ship {

    public:
	/**
	* @brief creats the ship in the spaces given
	*
	* @param fields list of space indexes
	*/
	Ship(const std::vector<int> &fields);
	/**
	* @brief checking the size of the ship
	*
	* checks size of list of indexes body_
	* @return size of ship
	* @see body_
	*/
	int GetSize();
	/**
	* @brief checking if the ship is sunk
	*
	* checks the value of the field is_afloat_
	* @return the value of the field is_afloat_
	* @see is_afloat_
	*/
	bool GetIsAfloat();
	/**
	* @brief sunks the ship
	*
	* sets the value of the field is_afloat_ to true
	* @see is_afloat_
	*/
	void Sunk();
	/**
	* @brief cheking position the ship
	*
	* checks if there is the ship on the field with the given index, if the index is on the list body_
	* @param number index of field
	* @return true - the ship is on the field; false - the ship is not on the field
	* @see body_
	*/
	bool IsInField(int number);
	/**
	* @brief cheking position the ship
	*
	* @return indexes, which are on the list body_
	* @see body_
	*/
	std::vector<int> GetIndex();

    private:
	/**
	* @brief lindexes of the fields on which the ship is
	*/
	std::vector<int> body_;
	/**
	* @brief information about the sinking of the ship
	*
	* the ship is afloat if all the spaces, on which it is, have been checked
	* true - the ship is afloat
	* false - the ship has not been afloat yet
	* @see body_
	*/
	bool is_afloat_;
};

#endif  // BATTLESHIPS_LIBCPP_INC_SHIP_H_
