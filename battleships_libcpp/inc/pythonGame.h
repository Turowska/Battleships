#ifndef BATTLESHIPS_LIBCPP_INC_PYTHON_GAME_H_
#define BATTLESHIPS_LIBCPP_INC_PYTHON_GAME_H_

#include "game.h"

#include <boost/python.hpp>
#include <iostream>

using namespace boost::python;

/**
* @brief klasa kontrolująca dostęp do klasy Game i dostarczająca odpowiedni interfejs do wywołania metod klasy Game z poziomu pythona
*/
class PythonGame{

    public:
	/**
	* @brief wywoływana z poziomu pythona jako Game(list, list)
	*
	* konstruktor zamienia listy na tablice std::array i tworzy obiekt klasy Game za pomocą konstruktora @see Game::Game(), którego wskaźnik przechowuje w polu @see game_
	* @param lista z danymi do stworzenia tablic dla pierwszego gracza
	* @param lista z danymi do stworzenia tablic dla drugiego gracza
	*/
	PythonGame(list tabListFirstPlayer, list tabListSecondPlayer);
	/**
	* @brief wywoływana z poziomu pythona jako Shot(int, int)
	*
	* metoda wywołuje i zwraca wartość zwracaną przez metodę @see Game::Shot() przekazując jako argument index pola i gracza
	* @param index pola, które ma zostać sprawdzone
	* @param index gracza wykonującego ruch
	* @return true - pole jest zajęte; false - pole jest wolne
	*/
	bool Shot(int number, int player);
	/**
	* @brief wywoływana z poziomu pythona jako IsSunk(int)
	*
	* metoda wywołuje i zwraca wartość zwracaną przez metodę @see Game::IsSunk() przekazując jako argument index pola
	* @param index pola, na którym znajduje się statek
	* @return true - statek jest zatopiony; false - statek nie jest zatopiony
	*/
	bool IsSunk(int number);
	/**
	* @brief wywoływana z poziomu pythona jako IsEnd()
	*
	* metoda wywołuje i zwraca wartość zwracaną przez metodę @see Game::IsEnd()
	* @return true - koniec gry; false - nie nastąpił jeszcze koniec gry
	*/
	bool IsEnd();
	/**
	* @brief wywoływana z poziomu pythona jako IsGood()
	*
	* metoda sprawdza czy w trakcie działania programu wystąpiły błędy, którego mogą skutkować łamaniem zasad gry
	* @return true - nie wystąpiły błędy; false - wystąpiły błędy
	*/
	bool IsGood();

    private:
	/**
	* @brief wskaźnik na oryginalny obiekt do którego kontrolowany jest dostęp
	*/
	Game* game_;
	/**
	* @brief pole przechowuje informacje, czy wystąpiły w trakcie działanie programu błędy
	*
	* true - nie wystąpiły błędy
	* false - wystąpiły błędy
	*/
	bool isGood_;

};

#endif  // BATTLESHIPS_LIBCPP_INC_PYTHON_GAME_H_
