#ifndef BATTLESHIPS_LIBCPP_INC_PYTHON_GAME_H_
#define BATTLESHIPS_LIBCPP_INC_PYTHON_GAME_H_

#include "game.h"

#include <boost/python.hpp>
#include <iostream>

using namespace boost::python;

/**
* @brief class that controls access to class Game and provides the appropriate interface for python
*/
class PythonGame{

    public:
	/**
	* @brief python: Game(list, list)
	*
	* changes list to array and shares Game::Game()
	* @param tabListFirstPlayer first player's list, which should has 100 values true/false
	* @param tabListSecondPlayer second player's list, which should has 100 values true/false
	* @see Game::Game()
	* @see game_
	*/
	PythonGame(list tabListFirstPlayer, list tabListSecondPlayer);
	/**
	* @brief python: Shot(int, int)
	*
	* shares Game::Shot(), with arguments:
	* number - index of field
	* player - index of player
	* @param number index of field
	* @param player index of player
	* @return true - field is occupied; false - field is unoccupied
	* @see Game::Shot()
	*/
	bool Shot(int number, int player);
	/**
	* @brief python: IsSunk(int)
	*
	* shares Game::IsSunk(), with arguments:
	* number - index of field
	* @param number index of field
	* @return list of indexes fields, on which the ship is, if ship is afloat. If ship is not afloat or any ship is not on field, list is empty
	* @see Game::IsSunk()
	*/
	list IsSunk(int number);
	/**
	* @brief python: IsEnd()
	*
	* shares Game::IsEnd()
	* @return true - play is end; false - play is not end
	* @see Game::IsEnd()
	*/
	bool IsEnd();
	/**
	* @brief python: IsGood()
	*
	* checks if there are any errors that may cause the program will not run properly
	* @return true - everything is correct; false - there are errors
	*/
	bool IsGood();

    private:
	/**
	* @brief the object to which access is controlled
	*/
	Game* game_;
	/**
	* @brief checks if everything is correct
	*
	* checks if there are any errors that may cause the program will not run properly
	* @return true - everything is correct; false - there are errors
	*/
	bool isGood_;

};

#endif  // BATTLESHIPS_LIBCPP_INC_PYTHON_GAME_H_
