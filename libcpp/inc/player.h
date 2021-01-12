#ifndef BATTLESHIPS_LIBCPP_INC_PLAYER_H_
#define BATTLESHIPS_LIBCPP_INC_PLAYER_H_

#include <vector>

#include "board.h"
#include "ship.h"

/**
* @brief presents a single player
*
* stores positions of ships and enemy's hits
*/
class Player {

    public:
	/**
	* @brief sets the ships
	*
	* creates and sets the ships based on array given
	* @param fields array with occupancy of fields
	*/
	Player(const std::array<bool, 100>& fields);
	/**
	* @brief allows the opponent to move
	*
	* checks field occupancy, and if field is occupied checks if the ship should be afloat by Sunk()
	* @param numer index of field
	* @return true - field is occupied; false - field is unoccupied
	* @see Sunk()
	*/
	bool Shot(int number);
	/**
	* @brief checks if ship is afloat
	*
	* checks if any ship is on the field, and if yes, checks if the ship is afloat
	* @param number index of field
	* @return list of indexes fields, on which the ship is, if ship is afloat. If ship is not afloat or any ship is not on field, list is empty
	*/
	std::vector<int> GetIsSunk(int number);
	/**
	* @brief checks if play is end
	*
	* checks if every ships are afloat
	* @return true - play is end; false - play is not end
	*/
	bool EndGame();
	/**
	* @brief checks if everything is correct
	*
	* checks if there are any errors that may cause the program will not run properly
	* @return true - everything is correct; false - there are errors
	*/
	bool IsGood();
    private:
	/**
	* @brief player's board
	*/
	Board board_;
	/**
	* @brief list of player's ships
	*/
	std::vector<Ship> ships_;
	/**
	* @brief information about errors
	*
	* true - everything is correct
	* false - there are errors
	*/
	bool isGood_;

	/**
	* @brief checks if the ship should be afloat
	*
	* sets ship as be afloat if every fields, on which it is, have been checked
	* @param number index of one of fields, on which ship is
	*/
	void Sunk(int number);
};

#endif  // BATTLESHIPS_LIBCPP_INC_PLAYER_H_
