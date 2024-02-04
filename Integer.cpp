#include "Integer.h"

#include <string>

Integer::Integer(int const value, bool const isTemp) : Type(isTemp), _value(value) {}

bool Integer::isPrintable() const {
    return true;
}

std::string Integer::toString() const {
    return std::to_string(this->_value);
}
