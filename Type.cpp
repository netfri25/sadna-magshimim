#include "Type.h"

Type::Type(std::string const& name) : _name(name) {};

std::string Type::get_name() const {
    return this->_name;
}
