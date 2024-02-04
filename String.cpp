#include "String.h"

String::String(std::string const& value, bool const isTemp) : Sequence(isTemp), _value(value) {}

bool String::isPrintable() const {
    return true;
}

std::string String::toString() const {
    return "'" + this->_value + "'";
}
