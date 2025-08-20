#include<iostream>
#include<memory>

#include "NumberToken.hpp"
#include "FloatNode.hpp"

NumberToken::NumberToken(float val) {
    NumberToken::val = val;
}

/*Node *NumberToken::toNode() {
    //TODO: convert token to node
    return nullptr;
}*/

TokenType NumberToken::getType() {
    return NUMBER;
}

void NumberToken::printToken() {
    std::cout << val;
}

int NumberToken::getPrecedence() {
    return -1;
}

std::expected<std::unique_ptr<Node>, std::string> NumberToken::parseToken(Parser &parser) {

}