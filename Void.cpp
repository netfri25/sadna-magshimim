#include "Void.h"

Void::Void() : Type("void") {}

bool Void::isPrintable() const {
    return false;
}

std::string Void::toString() const {
    return "()";
}
