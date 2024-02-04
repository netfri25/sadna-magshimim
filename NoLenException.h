#pragma once

#include "TypeErrorException.h"

class NoLenException : public TypeErrorException {
public:
    NoLenException(std::string const& name);

    virtual const char* what() const noexcept override;
};
