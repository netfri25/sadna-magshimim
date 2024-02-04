#include "NoLenException.h"
#include "TypeErrorException.h"

NoLenException::NoLenException(std::string const& name) : TypeErrorException("object of type `" + name + "` has no len()") { }

const char* NoLenException::what() const noexcept {
    return this->TypeErrorException::what();
}
