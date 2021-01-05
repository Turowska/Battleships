#ifndef BATTLESHIPS_LIBCPP_INC_GAME_H_
#define BATTLESHIPS_LIBCPP_INC_GAME_H_

#include <array>
#include <utility>

#include "player.h"

/**
* @brief klasa przechowująca i przetwarzająca dane gry w okręty
*/
class Game {

    public:
	/**
	* @brief stworzenie planszy na podstawie dwóch tablic
	*
	* konstruktor na podstawie dwóch tablic tworzy dwie plansze i ustawia na nich statki graczy
	* @param tablica na podstawie której ustawiane zostają statki pierwszego gracza
	* @param tablica na podstawie której ustawiane zostają statki drugiego gracza
	*/
	Game(const std::array<bool, 100>& firstPlayersBoard,
       const std::array<bool, 100>& secondPlayersBoard);
	/**
	* @brief zmiana gracza wykonującego ruch
	*
	* metoda zmienia wartość pola @see round_ na przeciwny
	*/
	void NextRound();
	/**
	* @brief wykonanie strzału
	*
	* gracz, którego kolej (określona za pomocą pola @see round_) wykonuje sprawdzenie danego pola z planszy przeciwnika
	* @param index pola
	* @return true - na danym polu był statek przeciwnika; false - na danym polu nie było statku przeciwnika
	*/
	bool Shot(int number);
	/**
	* @brief czy statek został zatopiony
	*
	* metoda sprawdza, czy statek przeciwnika gracza, którego kolej (określona za pomocą pola @see round_), znajdujący się między innymi na danym polu, został zatopiony
	* @param index pola
	* @return true - statek został zatopiony; flase - statek nie został zatopiony
	*/
	bool IsSunk(int number);
	/**
	* @brief czy koniec gry
	*
	* metoda sprawdza czy nastąpił koniec gry, tzn. czy wszystkie statki któregoś z graczy zostały zatopione
	* @return true - nastąpił koniec gry; false - nie nastąpił jeszcze koniec gry
	*/
	bool IsEnd();

    private:
	/**
	* @brief określenie gracza wykonującego ruch
	*
	* true - ruch wykonuje gracz pierwszy
	* false - ruch wykonuje gracz drugi
	*/
	bool round_;
	/**
	* @brief plansze graczy
	*
	* pole przechowuje dane potrzebne do gry dla poszczególnych graczy
	*/
	std::pair<Player, Player> players_;
};

#endif  // BATTLESHIPS_LIBCPP_INC_GAME_H_
