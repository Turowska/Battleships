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
	* metoda sprawdza rozmiar listy indexów pól na których stoi statek body_
	* @return ilość pól zajmowanych przez statek
	* @see body_
	*/
	int GetSize();
	/**
	* @brief sprawdza czy statek jest zatopiony
	*
	* metoda sprawdza wartość pola is_afloat_
	* @return zwraca wartość pola is_afloat_
	* @see is_afloat_
	*/
	bool GetIsAfloat();
	/**
	* @brief zatopienie statku
	*
	* metoda ustwia wartość pola is_afloat_ na true
	* @see is_afloat_
	*/
	void Sunk();
	/**
	* @brief sprawdza czy statek leży na danym polu
	*
	* metoda sprawdza czy dany index jest na liście body_
	* @param index pola
	* @return true - statek leży na danym polu; false - statek nie leży na danym polu
	* @see body_
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
	* przechowuje informację o sprawdzeniu wszystkich pól, których indexy znajdują się na liście body_
	* true - statek został zatopiony, wszystkie pola zostały sprawdzone
	* false - statek nie został zatopiony
	* @see body_
	*/
	bool is_afloat_;
};

#endif  // BATTLESHIPS_LIBCPP_INC_SHIP_H_
