#pragma once
#include "InterpreterException.h"
#include "Type.h"
#include "Helper.h"
#include <string>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <memory>


class Parser
{
public:
    static std::unique_ptr<Type> parseString(std::string const& str);

    // WARNING: may return nullptr
    static std::unique_ptr<Type> getType(std::string const& str);

private:

};
