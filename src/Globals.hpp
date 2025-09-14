#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include <array>
#include <map>
#include <any>
#include <string>

namespace Constants {
    constexpr char OPERATORS[5] = {'+', '-', '/', '*', '^'};
    
    enum Function {
        SIN = 0,
        COS,
        TAN,
        COTAN,
        SINH,
        COSH,
        TANH,
        LOG,
        LN,
        NUM_FUNCTIONS
    };

    std::map<std::string, std::any> mathFunctions;

    constexpr std::array FunctionMap = {"SIN"};
}

#endif