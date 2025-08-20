#include<iostream>

#include "LBracketToken.hpp"

LBracketToken::LBracketToken() {
}

/*Node *NumberToken::toNode() {
    //TODO: convert token to node
    return nullptr;
}*/

TokenType LBracketToken::getType() {
    return LBRACKET;
}

void LBracketToken::setRightBracket(int i) {
    LBracketToken::rightBracket = i;
}

void LBracketToken::printToken() {
    std::cout << "(";
}

int LBracketToken::getPrecedence() {
    return 0;
}

std::expected<std::unique_ptr<Node>, std::string> LBracketToken::parseToken() {


    return nullptr;
}