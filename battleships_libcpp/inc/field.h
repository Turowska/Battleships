#ifndef BATTLESHIPS_LIBCPP_INC_FIELD_H_
#define BATTLESHIPS_LIBCPP_INC_FIELD_H_

/**
        kontener przechowujący informacje o zajętości pola i oddaniu strzału na
dane pole
**/
class Field {
 public:
  Field();
  void SetIsOccupied(bool is_occupied);
  bool GetIsOccupied() const;
  bool GetIsHit() const;
  bool ShotField();

 private:
  bool is_occupied_;
  bool is_hit_;
};

#endif  // BATTLESHIPS_LIBCPP_INC_FIELD_H_
