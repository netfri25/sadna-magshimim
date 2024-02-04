#include "String.h"

String::String(std::string const& value) : Sequence(), _value(value) {}

bool String::isPrintable() const {
    return true;
}

std::string String::toString() const {
    char const c = this->_value.find("'") == std::string::npos ? '\'' : '"';
    return c + this->_value + c;
}
