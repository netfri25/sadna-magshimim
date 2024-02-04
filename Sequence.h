#pragma once

#include "Type.h"

class Sequence : public Type {
public:
    Sequence(std::string const& name);
    virtual int len() const = 0;
};
