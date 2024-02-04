#pragma once

#include "Type.h"

class Integer : public Type {
public:
    Integer(int const value);

    virtual bool isPrintable() const override;
    virtual std::string toString() const override;

private:
    int _value;
};
