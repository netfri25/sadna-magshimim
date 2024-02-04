#include "Void.h"

Void::Void(bool const isTemp) : Type(isTemp) {}

bool Void::isPrintable() const {
    return false;
}

std::string Void::toString() const {
    return "()";
}
