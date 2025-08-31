#include <iostream>

#include "FunctionToken.hpp"

FunctionToken::FunctionToken(std::string function) {
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
    std::cout << function;
}

int FunctionToken::getPrecedence() {
    return 4;
}

std::unique_ptr<Node> FunctionToken::parseToken() {
    return nullptr;
}