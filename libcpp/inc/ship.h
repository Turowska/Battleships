#ifndef BATTLESHIPS_LIBCPP_INC_SHIP_H_
#define BATTLESHIPS_LIBCPP_INC_SHIP_H_

#include <vector>

/**
* @brief klasa odpowiadająca statku
*
* kontener przytrzymujący i przetwarzający dane o statku: na których polach stoi statek, czy został zatopiony, jakiego jest rozmiaru
*/
class Ship {

    public:
	/**
	* @brief tworzy statek leżacy na podanych polach
	*
	* @param lista indexów pól na których stoi statek
	*/
	Ship(const std::vector<int> &fields);
	/**
	* @brief metoda oblicza rozmiar statku
	*
	* metoda sprawdza rozmiar listy indexów pól na których stoi statek @see body_
	* @return ilość pól zajmowanych przez statek
	*/
	int GetSize();
	/**
	* @brief sprawdza czy statek jest zatopiony
	*
	* metoda sprawdza wartość pola @see is_afloat_
	* @return zwraca wartość pola @see is_afloat_
	*/
	bool GetIsAfloat();
	/**
	* @brief zatopienie statku
	*
	* metoda ustwia wartość pola @see is_afloat_ na true
	*/
	void Sunk();
	/**
	* @brief sprawdza czy statek leży na danym polu
	*
	* metoda sprawdza czy dany index jest na liście @see body_
	* @param index pola
	* @return true - statek leży na danym polu; false - statek nie leży na danym polu
	*/
	bool IsInField(int number);

    private:
	/**
	* @brief lista indexów pól na których leży statek
	*/
	std::vector<int> body_;
	/**
	* @brief przechowuje informację o zatopieniu statku
	*
	* przechowuje informację o sprawdzeniu wszystkich pól, których indexy znajdują się na liście @see body_
	* true - statek został zatopiony, wszystkie pola zostały sprawdzone
	* false - statek nie został zatopiony
	*/
	bool is_afloat_;
};

#endif  // BATTLESHIPS_LIBCPP_INC_SHIP_H_
