#include "NameErrorException.h"

NameErrorException::NameErrorException(std::string const& name)
    : _full_exception("NameError: name `" + name + "` is not defined")
{}

const char* NameErrorException::what() const noexcept {
    return this->_full_exception.c_str();
}
