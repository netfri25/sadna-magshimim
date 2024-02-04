#include "LenFunction.h"
#include "Integer.h"
#include "List.h"
#include "TypeErrorException.h"

LenFunction::LenFunction() {};

bool LenFunction::isPrintable() const {
    return true;
}

std::string LenFunction::toString() const {
    return "<built-in function len>";
}

std::unique_ptr<Type> LenFunction::call(Type const& value) const {
    Sequence const* seq;
    if ((seq = dynamic_cast<Sequence const*>(&value)) != nullptr) {
        return std::make_unique<Integer>(seq->len());
    } else {
        throw TypeErrorException(value.get_name());
    }
}
