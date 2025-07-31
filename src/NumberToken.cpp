#include<iostream>

#include "NumberToken.hpp"

NumberToken::NumberToken(float val) {
    NumberToken::val = val;
}

Node *NumberToken::toNode() {
    //TODO: convert token to node
    return nullptr;
}

TokenType NumberToken::getType() {
    return NUMBER;
}

void NumberToken::printToken() {
    std::cout << val;
}