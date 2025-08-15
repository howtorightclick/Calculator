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