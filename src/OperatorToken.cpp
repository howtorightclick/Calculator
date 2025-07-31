#include <iostream>

#include "OperatorToken.hpp"

OperatorToken::OperatorToken(char val) {
    OperatorToken::val = val;
}

Node *OperatorToken::toNode() {
    // TODO: Convert token to node
    return nullptr;
}

TokenType OperatorToken::getType() {
    return OPERATOR;
}

void OperatorToken::printToken() {
    std::cout << val;
}