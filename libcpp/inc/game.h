#ifndef BATTLESHIPS_LIBCPP_INC_GAME_H_
#define BATTLESHIPS_LIBCPP_INC_GAME_H_

#include <array>
#include <vector>
#include <utility>

#include "player.h"

/**
* @brief class that keeps the state of the game - the battleships
*/
class Game {

    public:
	/**
	* @brief creats players' boards and sets their ships
	*
	* ships are sets base on given arrays
	* @param firstPlayerBoard first player's array
	* @param secondPlayerBoard second player's array
	*/
	Game(const std::array<bool, 100>& firstPlayersBoard,
       const std::array<bool, 100>& secondPlayersBoard);
	/**
	* @brief checks opponent's field
	*
	* player, which is determined by given index, makes a move and checks one of opponent's field, which index is given, sets the values of the fields round_
	* @param number index of field
	* @param player index of player
	* @return true - field is occupied; false - field is unoccupied
	* @see round_
	*/
	bool Shot(int number, int player);
	/**
	* @brief checks if opponent's ship is afloat
	*
	* player is determined by the field round_
	* @param number index of field
	* @return list of indexes fields, on which the ship is, if ship is afloat. If ship is not afloat or any ship is not on field, list is empty
	* @see round_
	*/
	std::vector<int> IsSunk(int number);
	/**
	* @brief checks if play is end
	*
	* checks if every ships one of players are afloat
	* @return true - play is end; false - play is not end
	*/
	bool IsEnd();
	/**
	* @brief checks if everything is correct
	*
	* checks if there are any errors that may cause the program will not run properly
	* @return true - everything is correct; false - there are errors
	*/
	bool IsGood();

    private:
	/**
	* @brief which player made the move
	*
	* true - first player
	* false - second player
	*/
	bool round_;
	/**
	* @brief information about errors
	*
	* true - everything is correct
	* false - there are errors
	*/
	bool isGood_;
	/**
	* @brief players' ships and decisions
	*
	*/
	std::pair<Player, Player> players_;
};

#endif  // BATTLESHIPS_LIBCPP_INC_GAME_H_
