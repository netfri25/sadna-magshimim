#pragma once

#include "Type.h"

#include <memory>

class Function : public Type {
public:
    Function();

    virtual std::unique_ptr<Type> call(Type const& value) const = 0;
};
