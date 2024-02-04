#include "Boolean.h"

Boolean::Boolean(bool const value, bool const isTemp) : Type(isTemp), _value(value) {}

bool Boolean::isPrintable() const {
    return true;
}

std::string Boolean::toString() const {
    return this->_value ? "True" : "False";
}
