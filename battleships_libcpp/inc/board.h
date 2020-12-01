#ifndef BATTLESHIPS_LIBCPP_INC_BOARD_H_
#define BATTLESHIPS_LIBCPP_INC_BOARD_H_

#include <array>
#include "field.h"

/**
        kontener przechowujący 100 kontenerów klasy Field
**/

class Board {
 public:
  explicit Board(const std::array<bool, 100>& fields);
  bool GetIsOccupied(int number) const;
  bool GetIsHit(int number) const;
  bool Shot(int number);

 private:
  std::array<Field, 100> fields_;
};

#endif  // BATTLESHIPS_LIBCPP_INC_BOARD_H_
