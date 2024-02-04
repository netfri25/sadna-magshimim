#pragma once

#include "Function.h"

class LenFunction : public Function {
public:
    LenFunction();

    virtual bool isPrintable() const override;
    virtual std::string toString() const override;
    virtual std::unique_ptr<Type> call(Type const& value) const override;
};
