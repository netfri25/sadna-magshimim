#include "Integer.h"

#include <string>

Integer::Integer(int const value) : Type("int"), _value(value) {}

bool Integer::isPrintable() const {
    return true;
}

std::string Integer::toString() const {
    return std::to_string(this->_value);
}
