#pragma once

#include <string>

#include "InterpreterException.h"

class TypeErrorException : public InterpreterException {
public:
    TypeErrorException(std::string const& name);

    virtual const char* what() const noexcept;

private:
    std::string _full_exception;
};
