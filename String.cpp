#include "String.h"

String::String(std::string const& value) : Sequence("str"), _value(value) {}

bool String::isPrintable() const {
    return true;
}

std::string String::toString() const {
    char const c = this->_value.find("'") == std::string::npos ? '\'' : '"';
    return c + this->_value + c;
}

int String::len() const {
    return this->_value.size();
}
