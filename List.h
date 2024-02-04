#pragma once

#include <vector>
#include <memory>

#include "Sequence.h"

class List : public Sequence {
public:
    List();

    void push(std::shared_ptr<Type> const& element);
    std::vector<std::shared_ptr<Type>> const& get_ref() const;

    virtual int len() const override;
    virtual bool isPrintable() const override;
    virtual std::string toString() const override;

private:
    std::vector<std::shared_ptr<Type>> _elements;
};
