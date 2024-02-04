#pragma once

#include <string>

class Type {
public:
    Type(std::string const& name);
    Type(const Type &) = default;
    Type(Type &&) = default;

    std::string get_name() const;

    virtual bool isPrintable() const = 0;
    virtual std::string toString() const = 0;

private:
    std::string _name;
};
