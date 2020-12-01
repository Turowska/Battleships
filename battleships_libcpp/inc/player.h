#ifndef BATTLESHIPS_LIBCPP_INC_PLAYER_H_
#define BATTLESHIPS_LIBCPP_INC_PLAYER_H_

#include <utility>
#include <vector>

#include "board.h"
#include "ship.h"

class Player {
 public:
  explicit Player(const std::array<bool, 100>& fields);
  bool Shot(int number);
  bool GetIsSunk(int number);
  bool EndGame();

 private:
  Board board_;
  std::vector<Ship> ships_;

  void Sunk(int number);
};

#endif  // BATTLESHIPS_LIBCPP_INC_PLAYER_H_
