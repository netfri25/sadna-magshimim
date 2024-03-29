#pragma once

#include "Sequence.h"

class String : public Sequence {
public:
    String(std::string const& value);

    virtual int len() const override;
    virtual bool isPrintable() const override;
    virtual std::string toString() const override;

private:
    std::string _value;
};
