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
	* @brief wykonanie strzału
	*
	* gracz wykonuje sprawdzenie danego pola z planszy przeciwnika, możliwa zamiana gracza wykonującego ruch, tzn. wartości pola round_
	* @param index pola
	* @param index określający gracza wykonującego ruch
	* @return true - na danym polu był statek przeciwnika; false - na danym polu nie było statku przeciwnika
	* @see round_
	*/
	bool Shot(int number, int player);
	/**
	* @brief czy statek został zatopiony
	*
	* metoda sprawdza, czy statek przeciwnika gracza, którego kolej (określona za pomocą pola round_), znajdujący się między innymi na danym polu, został zatopiony
	* @param index pola
	* @return true - statek został zatopiony; flase - statek nie został zatopiony
	* @see round_
	*/
	bool IsSunk(int number);
	/**
	* @brief czy koniec gry
	*
	* metoda sprawdza czy nastąpił koniec gry, tzn. czy wszystkie statki któregoś z graczy zostały zatopione
	* @return true - nastąpił koniec gry; false - nie nastąpił jeszcze koniec gry
	*/
	bool IsEnd();
	/**
	* @brief czy wystąpiły błędy
	*
	* metoda sprawdza czy w trakcie działania programu wystąpiły błędy, którego mogą skutkować łamaniem zasad gry
	* @return true - nie wystąpiły błędy; false - wystąpiły błędy
	*/
	bool IsGood();

    private:
	/**
	* @brief określenie gracza wykonującego ruch
	*
	* true - ruch wykonuje gracz pierwszy
	* false - ruch wykonuje gracz drugi
	*/
	bool round_;
	/**
	* @brief pole przechowuje informacje, czy wystąpiły w trakcie działanie programu błędy
	*
	* true - nie wystąpiły błędy
	* false - wystąpiły błędy
	*/
	bool isGood_;
	/**
	* @brief plansze graczy
	*
	* pole przechowuje dane potrzebne do gry dla poszczególnych graczy
	*/
	std::pair<Player, Player> players_;
};

#endif  // BATTLESHIPS_LIBCPP_INC_GAME_H_
