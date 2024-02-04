#pragma once

#include <string>

#include "InterpreterException.h"

class NameErrorException : public InterpreterException {
public:
    NameErrorException(std::string const& name);

    virtual const char* what() const noexcept;

private:
    std::string _full_exception;
};
