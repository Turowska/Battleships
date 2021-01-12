#ifndef BATTLESHIPS_LIBCPP_INC_FIELD_H_
#define BATTLESHIPS_LIBCPP_INC_FIELD_H_

/**
* @brief presents a single field on the player's board
*
* stores information about the field being occupied and the shot being taken on this field
*/
class Field {

    public:
	/**
	* @brief creates an unoccupied and unchecked field
	*
	* the constructor sets the values of the fields is_occupied_ and is_hit_ to false
	* @see is_occupied_
	* @see is_hit_
	*/
	Field();
	/**
	* @brief takes up and releases the field
	*
	* sets the value of the field is_occupied_ to the given value
	* @param is_occupied value to be set
	* @see is_occupied_
	*/
	void SetIsOccupied(bool is_occupied);
	/**
	* @brief checks whether the field is occupied
	*
	* checks the value of the field is_occupied_
	* @return the value of the field is_occupied_
	* @see is_occupied_
	*/
	bool GetIsOccupied() const;
	/**
	* @brief checks whether the field has been checked
	*
	* checks the value of the field is_hit_
	* @return the value of the field is_hit_
	* @see is_hit_
	*/
	bool GetIsHit() const;
	/**
	* @brief checks the field
	*
	* sets the value of the field is_hit_ to true and checks the value of the field is_occupied_
	* @return the value of the field is_occupied_
	* @see is_hit_
	* @see is_occupied_
	*/
	bool ShotField();

    private:
	/**
	* @brief stores information about the field occupancy
	*
	* true - the field is occupied
	* false - the field is unoccupied
	*/
	bool is_occupied_;
	/**
	* @brief stores information about checking the field
	*
	* true - the field has been checked
	* false - the field has not been checked yet
	*/
	bool is_hit_;
};

#endif  // BATTLESHIPS_LIBCPP_INC_FIELD_H_
