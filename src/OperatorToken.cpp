#include <iostream>
#include <memory>

#include "OperatorToken.hpp"
#include "OperatorNode.hpp"

OperatorToken::OperatorToken(std::string content, bool _unary):
isUnary (_unary),
content (content)
{
}

/*Node *OperatorToken::toNode() {
    // TODO: Convert token to node
    return nullptr;
}*/

TokenType OperatorToken::getType() const {
    return OPERATOR;
}

void OperatorToken::printToken() const {
    std::cout << content;
}

int OperatorToken::getPrecedence() const {
    switch (content[0])
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
        return 1;
    case '-':
        if (isUnary)
        {
            return 4;
        }
        return 1;
    default:
        return -1;
    }
}

std::string OperatorToken::getContent() const {
    return content;
}

std::unique_ptr<OperatorToken> OperatorToken::clone() const {
    return std::make_unique<OperatorToken>(content, isUnary);
};

bool OperatorToken::isRightAssociative() const {
    return content[0] == '^';
}

void OperatorToken::accept(Parser &parser) const {
    parser.process(*this);
}