#ifndef BATTLESHIPS_LIBCPP_INC_PLAYER_H_
#define BATTLESHIPS_LIBCPP_INC_PLAYER_H_

#include <vector>

#include "board.h"
#include "ship.h"

/**
* @brief klasa odpowiadająca stanu gry po stronie pojedynczego gracza
*
* klasa przechowująca planszę, ustawienie na niej statków, i strzały przeciwnika pojedynczego gracza, pozwalająca na wykonanie ruchu przez przeciwnika
*/
class Player {

    public:
	/**
	* @brief ustawienie statków na planszy
	*
	* konstruktor tworzy statki, oraz planszę z ustawionymi na niej statkami zgodnie z podaną tablicą
	* @param tablica wskazująca na jakich polach stoją statki
	*/
	Player(const std::array<bool, 100>& fields);
	/**
	* @brief dokonanie przez przeciwnika strzału na dane pole
	*
	* metoda odpowiadająca dokonaniu strzału przez przeciwnika na podane pole; w przypadku trafienia sprawdza czy dany statek powinien być zatopiony zapomocą metody Sunk()
	* @param numer indexu pola
	* @return true - na danym polu znajdował się statek; false - dane pole było wolne
	* @see Sunk()
	*/
	bool Shot(int number);
	/**
	* @brief sprawdzenie czy statek jest zatopiony
	*
	* metoda sprawdza czy statek znajdujący się między innymi na podanym polu jest zatopiony, tzn. czy wszystkie pola na których się znajuje zostały sprawdzone
	* @param index pola na którym znajduje się statek
	* @return true - statek został zatopiony; false - statek nie został zatopiony
	*/
	bool GetIsSunk(int number);
	/**
	* @brief sprawdzenie czy gra została zakończona
	*
	* metoda sprawdzająca czy wszystkie statki zosały zatopione, co oznacza koniec gry i przegraną danego gracza
	* @return true - wszystkie statki zostały zatopione; false - niewszystkie statki zostały zatopione
	*/
	bool EndGame();
	/**
	* @brief czy wystąpiły błędy
	*
	* metoda sprawdza czy w trakcie działania programu wystąpiły błędy, którego mogą skutkować łamaniem zasad gry
	* @return true - nie wystąpiły błędy; false - wystąpiły błędy
	*/
	bool IsGood();
    private:
	/**
	* @brief plansza gracza
	*/
	Board board_;
	/**
	* @brief zbiór statków danego gracza
	*/
	std::vector<Ship> ships_;
	/**
	* @brief pole przechowuje informacje, czy wystąpiły w trakcie działanie programu błędy
	*
	* true - nie wystąpiły błędy
	* false - wystąpiły błędy
	*/
	bool isGood_;

	/**
	* @brief sprawdzenie czy dany statek powinien być zatopiony
	*
	* metoda sprawdza czy wszystkie pola na których stoi statek zostały sprawdzone, jeżeli tak zmienia stan statku na zatopiony
	* @param index jednego z pól na którym stoi statek
	*/
	void Sunk(int number);
};

#endif  // BATTLESHIPS_LIBCPP_INC_PLAYER_H_
