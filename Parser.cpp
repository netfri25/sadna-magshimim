#include "Parser.h"

// std
#include <memory>
#include <sstream>
#include <iostream>
#include <stdexcept>

// types
#include "String.h"
#include "Boolean.h"
#include "Integer.h"

// exceptions
#include "SyntaxException.h"
#include "IndentationException.h"

std::unique_ptr<Type> Parser::parseString(std::string const& str) {
    if (std::isspace(str[0])) {
        throw IndentationException();
    }

    if (str.length() == 0) {
        return nullptr;
    }

    std::unique_ptr<Type> value = Parser::getType(str);
    if (value == nullptr) {
        throw SyntaxException();
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

    return nullptr;
}
