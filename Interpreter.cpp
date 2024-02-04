#include "Type.h"
#include "InterpreterException.h"
#include "Parser.h"
#include <iostream>
#include <limits>

#define WELCOME "Welcome to Magshimim Python Interperter version 1.0 by "
#define YOUR_NAME "[Netanel Friedman]"

int main(int argc, char** argv) {
    std::cout << WELCOME << YOUR_NAME << std::endl;

    std::string input_string;

    // get new command from user
    std::cout << ">>> ";
    std::getline(std::cin, input_string);

    while (input_string != "quit()") {
        // parsing command
        try {
            Parser::parseString(input_string);
        } catch (InterpreterException const& e) {
            std::cerr << e.what() << std::endl;
        }

        // get new command from user
        std::cout << ">>> ";
        std::getline(std::cin, input_string);
    }

    return 0;
}
