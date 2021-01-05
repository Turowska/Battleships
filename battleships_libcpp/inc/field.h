#ifndef BATTLESHIPS_LIBCPP_INC_FIELD_H_
#define BATTLESHIPS_LIBCPP_INC_FIELD_H_

/**
* @brief klasa odpowiadająca pojedynczemu polu na planszy
*
* kontener przechowujący informacje o zajętości pola i oddaniu strzału na dane pole
*/
class Field {

    public:
	/**
	* @brief konstruktor tworzący niezajęte i niesprawdzone pole
	*
	* konstruktor, ustawia wartość pól @see is_occupied_ i @see is_hit_ na false
	*/
	Field();
	/**
	* @brief zajmuje i zwalnia pole
	*
	* metoda ustawia wartość pola @see is_occupied_
	* @param is_occupied wartość jaka ma zostać przypisana polu @see is_occupied_
	*/
	void SetIsOccupied(bool is_occupied);
	/**
	* @brief sprawdza zajętość pola
	*
	* metoda sprawdza wartość pola @see is_occupied_
	* @return wartość pola @see is_occupied_
	*/
	bool GetIsOccupied() const;
	/**
	* @brief sprawdza czy pole zostało sprawdzone
	*
	* metoda sprawdza wartość pola @see is_hit_
	* @return wartość pola @see is_hit_
	*/
	bool GetIsHit() const;
	/**
	* @brief sprawdza pole
	*
	* metoda ustwaia pole @see is_hit_ na true i sprawdza wartość pola @see is_occupied_
	* @return wartość pola @see is_occupied_
	*/
	bool ShotField();

    private:
	/**
	* @brief zajętość pola
	*
	* przechowuje informacje czy dane pole jest zajęte
	* true - pole jest zajęte
	* false - pole jest wolne
	*/
	bool is_occupied_;
	/**
	* @brief czy pole zostało już sprawdzone
	*
	* przechowuje informacje czy dane pole zostało sprawdzone
	* true - pole zostało sprawdzone
	* false - pole nie zostało jeszcze sprawdzone
	*/
	bool is_hit_;
};

#endif  // BATTLESHIPS_LIBCPP_INC_FIELD_H_
