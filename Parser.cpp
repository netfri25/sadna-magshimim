#include "Parser.h"

// std
#include <functional>
#include <vector>
#include <memory>
#include <sstream>
#include <iostream>
#include <stdexcept>

// types
#include "List.h"
#include "Void.h"
#include "String.h"
#include "Boolean.h"
#include "Integer.h"
#include "LenFunction.h"
#include "TypeFunction.h"

// exceptions
#include "SyntaxException.h"
#include "NameErrorException.h"
#include "IndentationException.h"

std::unordered_map<std::string, std::shared_ptr<Type>> Parser::_variables = {
    { "len", std::make_shared<LenFunction>() },
    { "type", std::make_shared<TypeFunction>() },
};

std::shared_ptr<Type> Parser::parseString(std::string const& str) {
    if (std::isspace(str[0])) {
        throw IndentationException();
    }

    if (str.length() == 0) {
        return nullptr;
    }

    std::unique_ptr<Type> result = parseFunction(str);
    if (result != nullptr) {
        std::cout << result->toString() << std::endl;
        return result;
    }

    if (makeAssignment(str)) {
        return std::make_unique<Void>();
    }

    std::unique_ptr<Type> value = Parser::getType(str);
    if (value == nullptr) {
        if (isLegalVarName(str)) {
            std::shared_ptr<Type> variable = Parser::getVariableValue(str);
            if (variable == nullptr) {
                throw NameErrorException(str);
            }
            std::cout << variable->toString() << std::endl;
            return variable;
        } else {
            throw SyntaxException();
        }
    }

    if (value->isPrintable()) {
        std::cout << value->toString() << std::endl;
    }

    return value;
}

std::unique_ptr<Type> Parser::getType(std::string const& str) {
    if (Helper::isBoolean(str)) {
        if (str == "True") {
            return std::make_unique<Boolean>(true);
        } else if (str == "False") {
            return std::make_unique<Boolean>(false);
        } else {
            throw std::invalid_argument("isBoolean not working properly");
        }
    }

    if (Helper::isString(str)) {
        // trims the surrounding ""
        return std::make_unique<String>(str.substr(1, str.length() - 2));
    }

    if (Helper::isInteger(str)) {
        std::istringstream stream(str);
        int num = 0;
        stream >> num;
        return std::make_unique<Integer>(num);
    }

    if (str[0] == '[') {
        std::string s = str.substr(1);
        Helper::ltrim(s);

        std::unique_ptr<List> list = std::make_unique<List>();
        std::string::size_type comma = std::string::npos;
        while ((comma = s.find(',')) != std::string::npos) {
            std::string value_str = s.substr(0, comma);
            Helper::trim(value_str);
            std::shared_ptr<Type> value = Parser::getType(value_str);
            list->push(value);
            s = s.substr(comma+1);
        }

        std::string::size_type list_end = s.find(']');
        if (list_end == std::string::npos) {
            throw SyntaxException();
        }

        std::string value_str = s.substr(0, list_end);
        Helper::trim(value_str);
        std::shared_ptr<Type> value = Parser::getType(value_str);
        list->push(value);

        return list;
    }

    return nullptr;
}

// should accept a trimmed string
bool Parser::isLegalVarName(std::string const& str) {
    bool const first_ok = Helper::isUnderscore(str[0]) || Helper::isLowerLetter(str[0]);

    if (!first_ok)
        return false;

    for (char const& c : str)
        if (!Helper::isUnderscore(c) && !Helper::isLetter(c) && !Helper::isDigit(c))
            return false;

    return true;
}

bool Parser::makeAssignment(std::string const& str) {
    std::string s = str;
    Helper::trim(s);
    std::string::size_type equal_sign = std::string::npos;
    // make sure it occures only once, and it has something on both sides
    bool const depressed = s.front() == '=' || s.back() == '=';
    bool const only_once = (equal_sign = str.find('=')) != std::string::npos && str.find('=', equal_sign+1) == std::string::npos;

    if (depressed || !only_once)
        return false;

    std::string name = str.substr(0, equal_sign);
    std::string value_str = str.substr(equal_sign + 1);
    Helper::trim(name);
    Helper::trim(value_str);

    if (!isLegalVarName(name)) {
        throw SyntaxException();
    }

    std::unique_ptr<Type> value = Parser::getType(value_str);
    if (value == nullptr) {
        if (!isLegalVarName(value_str)) {
            throw SyntaxException();
        }

        if (!Parser::_variables.count(value_str)) {
            throw NameErrorException(value_str);
        }

        // when the value of `src` is a List (shallow copy object)
        if (dynamic_cast<List*>(Parser::_variables[value_str].get()) != nullptr) {
            // don't make a copy
            Parser::_variables.insert({ name, Parser::_variables[value_str] });
        } else {
            // make a copy
            Parser::_variables[name] = Parser::_variables[value_str];
        }

        return true;
    }

    Parser::_variables[name] = std::move(value);
    return true;
}

std::shared_ptr<Type> Parser::getVariableValue(std::string const& str) {
    if (Parser::_variables.count(str)) {
        return Parser::_variables[str];
    } else {
        return nullptr;
    }
}

std::unique_ptr<Type> Parser::parseFunction(std::string const& str) {
    std::string::size_type open_paren = str.find('(');
    if (open_paren == std::string::npos) {
        return nullptr;
    }

    std::string name = str.substr(0, open_paren);
    std::string rest = str.substr(open_paren+1);

    std::string::size_type close_paren = rest.find_last_of(')');
    if (close_paren == std::string::npos) {
        throw SyntaxException();
    }

    std::shared_ptr<Type> value_to_pass = Parser::getType(rest.substr(0, close_paren));
    if (value_to_pass == nullptr) {
        throw SyntaxException();
    }

    std::shared_ptr<Type> function_value = getVariableValue(name);
    if (function_value == nullptr) {
        throw NameErrorException(name);
    }

    Function const* func;
    if ((func = dynamic_cast<Function const*>(function_value.get())) == nullptr) {
        throw SyntaxException();
    }

    return func->call(*value_to_pass);
}
