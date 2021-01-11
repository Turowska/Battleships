#include "ship.h"

Ship::Ship(const std::vector<int> &fields) : is_afloat_(false) {
    body_ = fields;
}

int Ship::GetSize() {
    return body_.size();
}

bool Ship::GetIsAfloat() {
    return is_afloat_;
}

void Ship::Sunk() {
    is_afloat_ = true;
}

bool Ship::IsInField(int number) {
    for (auto i = body_.begin(); i != body_.end(); ++i) {
	if ((*i) == number) {
	    return true;
	}
    }
    return false;
}
