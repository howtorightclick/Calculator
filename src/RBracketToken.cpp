#include<iostream>

#include "RBracketToken.hpp"

RBracketToken::RBracketToken() {
}

/*Node *NumberToken::toNode() {
    //TODO: convert token to node
    return nullptr;
}*/

TokenType RBracketToken::getType() {
    return RBRACKET;
}

void RBracketToken::printToken() {
    std::cout << ")";
}

int RBracketToken::getPrecedence() {
    return 0;
}

std::expected<std::unique_ptr<Node>, std::string> RBracketToken::parseToken(Parser &parser) {

    return nullptr;
}