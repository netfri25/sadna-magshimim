#include "Type.h"

Type::Type(bool const isTemp) : _isTemp(isTemp) {};

bool Type::getIsTemp() const {
    return this->_isTemp;
}

void Type::setIsTemp(bool const isTemp) {
    this->_isTemp = isTemp;
}
