#include "inc/field.h"

Field::Field() : is_occupied_(false), is_hit_(false) {}

void Field::SetIsOccupied(bool is_occupied) { is_occupied_ = is_occupied; }

bool Field::GetIsOccupied() { return is_occupied_; }

bool Field::GetIsHit() { return is_hit_; }

bool Field::ShotField() {
  is_hit_ = true;
  return is_occupied_;
}
