#include "Parser.h"
#include "IndentationException.h"
#include <iostream>

Type* Parser::parseString(std::string str) {
    if (str.length() > 0) {
        std::cout << str << std::endl;
    }

    if (std::isspace(str[0])) {
        throw IndentationException();
    }

    return nullptr;
}
