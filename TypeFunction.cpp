#include "TypeFunction.h"

#include "String.h"

bool TypeFunction::isPrintable() const {
    return true;
}

std::string TypeFunction::toString() const {
    return "<built-in function type>";
}

std::unique_ptr<Type> TypeFunction::call(Type const& value) const {
    return std::make_unique<String>("<type '" + value.get_name() + "'>");
}
