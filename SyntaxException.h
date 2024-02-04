#pragma once

#include "InterpreterException.h"

class SyntaxException : public InterpreterException {
    virtual const char* what() const noexcept override;
};
