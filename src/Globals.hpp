#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include <array>

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

    constexpr std::array FunctionMap = {"SIN"};
}

#endif