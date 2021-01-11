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
	* konstruktor, ustawia wartość pól is_occupied_ i is_hit_ na false
	* @see is_occupied_
	* @see is_hit_
	*/
	Field();
	/**
	* @brief zajmuje i zwalnia pole
	*
	* metoda ustawia wartość pola is_occupied_
	* @param is_occupied wartość jaka ma zostać przypisana polu is_occupied_
	* @see is_occupied_
	*/
	void SetIsOccupied(bool is_occupied);
	/**
	* @brief sprawdza zajętość pola
	*
	* metoda sprawdza wartość pola is_occupied_
	* @return wartość pola is_occupied_
	* @see is_occupied_
	*/
	bool GetIsOccupied() const;
	/**
	* @brief sprawdza czy pole zostało sprawdzone
	*
	* metoda sprawdza wartość pola is_hit_
	* @return wartość pola is_hit_
	* @see is_hit_
	*/
	bool GetIsHit() const;
	/**
	* @brief sprawdza pole
	*
	* metoda ustwaia pole is_hit_ na true i sprawdza wartość pola is_occupied_
	* @return wartość pola is_occupied_
	* @see is_hit_
	* @see is_occupied_
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
