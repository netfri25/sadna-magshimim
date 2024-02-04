#pragma once

#include <string>

class Type {
public:
    Type(bool const isTemp = false);

    bool getIsTemp() const;
    void setIsTemp(bool const is_temp);

    virtual bool isPrintable() const = 0;
    virtual std::string toString() const = 0;

private:
    bool _isTemp;
};
