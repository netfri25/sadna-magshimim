#pragma once

#include "Function.h"

class TypeFunction : public Function {
    virtual bool isPrintable() const override;
    virtual std::string toString() const override;
    virtual std::unique_ptr<Type> call(Type const& value) const override;
};
