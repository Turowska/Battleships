#include "board.h"

Board::Board(const std::array<bool, 100>& fields) {
  auto j = fields_.begin();
  for (auto i = fields.begin(); i != fields.end() && j != fields_.end();
       ++i, ++j) {
    (*j).SetIsOccupied(*i);
  }
}

bool Board::GetIsOccupied(int number) const {
  return fields_[number].GetIsOccupied();
}

bool Board::GetIsHit(int number) const { return fields_[number].GetIsHit(); }

bool Board::Shot(int number) { return fields_[number].ShotField(); }
