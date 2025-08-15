#include <iostream>
#include "FunctionToken.hpp"

FunctionToken::FunctionToken(Function function) {
    FunctionToken::function = function;
}

/*Node *FunctionToken::toNode() {
    // TODO: convert token into node
    return nullptr;
}*/

TokenType FunctionToken::getType() {
    return FUNCTION;
}

void FunctionToken::printToken() {
    if (function == SIN) {
        std::cout << "SIN";
    } else if (function == COS) {
        std::cout << "cos";
    } else if (function == TAN) {
        std::cout << "tan";
    } else if (function == SINH) {
        std::cout << "sinh";
    } else if (function == COSH) {
        std::cout << "cosh";
    } else if (function == TANH) {
        std::cout << "tanh";
    }
}