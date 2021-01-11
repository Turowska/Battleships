#ifndef BATTLESHIPS_LIBCPP_INC_BOARD_H_
#define BATTLESHIPS_LIBCPP_INC_BOARD_H_

#include <array>
#include "field.h"

/**
* @brief klasa odpowiadająca planszy
*
* kontener przechowujący 100 kontenerów klasy Field
*/
class Board {

    public:
	/**
	* @brief tworzy planszę z ustawionymi statkami według tablicy array<bool, 100>
	*
	* tworzy tablicę 100 pól o zajętości każdego pola odpowiadającego wartości pola w tablicy array<bool, 100>
	* @param tablica na podstawie której ustalana jest zajętość pól w tablicy
	*/
	Board(const std::array<bool, 100>& fields);
	/**
	* @brief sprawdza zajętość pola o podanym indexie
	*
	* @param index pola, którego zajętość ma zostać sprawdzona
	* @return zajętość sprawdzonego pola (true - pole jest zajęte; false - pole jest wolne)
	*/
	bool GetIsOccupied(int number) const;
	/**
	* @brief sprawdza czy pola o podanym indexie zostało sprawdzone
	*
	* @param index pola, które ma zostać sprawdzone
	* @return czy polezostało sprawdzone (true - pole zostało sprawdzone; false - pole nie zostało jeszcze sprawdzone)
	*/
	bool GetIsHit(int number) const;
	/**
	* @brief oodanie strzału
	*
	* metoda zmienia dane pole na sprawdzone i sprawdza jego zajętość
	* @param index pola
	* @return zajętość pola (true - pole jest zajęte; false - pole jest wolne
	*/
	bool Shot(int number);

    private:
	/**
	* tablica pól
	*/
	std::array<Field, 100> fields_;
};

#endif  // BATTLESHIPS_LIBCPP_INC_BOARD_H_
