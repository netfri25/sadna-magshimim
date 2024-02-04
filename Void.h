#pragma once

#include "Type.h"

class Void : public Type {
public:
    Void(bool const isTemp = false);

    virtual bool isPrintable() const override;
    virtual std::string toString() const override;
};
