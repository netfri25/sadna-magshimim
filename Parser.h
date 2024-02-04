#pragma once
#include "InterpreterException.h"
#include "Type.h"
#include "Helper.h"
#include "Function.h"
#include <string>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <memory>


class Parser {
public:
    static std::shared_ptr<Type> parseString(std::string const& str);
    static std::unique_ptr<Type> getType(std::string const& str);

private:
    static bool isLegalVarName(std::string const& str);
    static bool makeAssignment(std::string const& str);
    static std::shared_ptr<Type> getVariableValue(std::string const& str);
    static std::unique_ptr<Type> parseFunction(std::string const& str);

    static std::unordered_map<std::string, std::shared_ptr<Type>> _variables;
};
