#include <iostream>

#include "BracketToken.hpp"
#include "OperatorNode.hpp"

BracketToken::BracketToken(bool isLeft):
isLeft_ (isLeft)
{

}

std::string BracketToken::getContent() const {
    if (isLeft_) {
        return "(";
    }
    return ")";
}

TokenType BracketToken::getType() const {
    if (isLeft_) {
        return LBRACKET;
    } else {
        return RBRACKET;
    }
}

void BracketToken::printToken() const {
    if (isLeft_) {
        std::cout << '(';
    } else {
        std::cout << ')';
    }
}

int BracketToken::getPrecedence() const {
    return -1;
}

bool BracketToken::isLeft() const {
    return isLeft_;
}

void BracketToken::accept(Parser &parser) const {
    parser.process(*this);
}