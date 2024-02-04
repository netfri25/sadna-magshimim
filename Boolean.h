#pragma once

#include "Type.h"
#include <string>

class Boolean : public Type {
public:
    Boolean(bool const value, bool const isTemp = false);

    virtual bool isPrintable() const override;
    virtual std::string toString() const override;

private:
    bool _value;
};
