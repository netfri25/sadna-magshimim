#include "TypeErrorException.h"

TypeErrorException::TypeErrorException(std::string const& _full_exception) : _full_exception("TypeError: " + _full_exception) {}

const char* TypeErrorException::what() const noexcept {
    return this->_full_exception.c_str();
}
