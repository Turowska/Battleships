#ifndef BATTLESHIPS_LIBCPP_INC_SHIP_H_
#define BATTLESHIPS_LIBCPP_INC_SHIP_H_

#include <vector>

/**
        kontener przytrzymujący dane o statku: na których polach stoi statek,
czy został zatopiony, jakiego jest rozmiaru
**/

struct Ship {
 public:
  explicit Ship(const std::vector<int> &fields);
  int GetSize();
  bool GetIsAfloat();
  void Sunk();
  bool IsInField(int number);

 private:
  std::vector<int> body_;
  bool is_afloat_;
};

#endif  // BATTLESHIPS_LIBCPP_INC_SHIP_H_
