#include<iostream>
#include<memory>
#include <queue>

#include "NumberToken.hpp"
#include "FloatNode.hpp"

NumberToken::NumberToken(float val) {
    NumberToken::val = val;
}

/*Node *NumberToken::toNode() {
    //TODO: convert token to node
    return nullptr;
}*/

TokenType NumberToken::getType() const {
    return NUMBER;
}

void NumberToken::printToken() const {
    std::cout << val;
}

int NumberToken::getPrecedence() const {
    return -1;
}

std::string NumberToken::getContent() const {
    return "";
}

float NumberToken::getVal() const {
    return val;
}

void NumberToken::accept(Parser &parser) const {
    parser.process(*this);
}