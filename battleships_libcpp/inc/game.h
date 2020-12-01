#ifndef BATTLESHIPS_LIBCPP_INC_GAME_H_
#define BATTLESHIPS_LIBCPP_INC_GAME_H_

#include <array>
#include <utility>

#include "player.h"

class Game {
 public:
  Game(const std::array<bool, 100>& firstPlayersBoard,
       const std::array<bool, 100>& secondPlayersBoard);
  void NextRound();
  bool Shot(int number);
  bool IsSunk(int number);
  bool IsEnd();

 private:
  bool round_;
  std::pair<Player, Player> players_;
};

#endif  // BATTLESHIPS_LIBCPP_INC_GAME_H_
