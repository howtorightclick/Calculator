#include <iostream>

#include "OperatorToken.hpp"
#include "InfixOpNode.hpp"

OperatorToken::OperatorToken(char _val, bool _unary):
val (_val),
isUnary (_unary)
{
}

/*Node *OperatorToken::toNode() {
    // TODO: Convert token to node
    return nullptr;
}*/

TokenType OperatorToken::getType() {
    return OPERATOR;
}

void OperatorToken::printToken() {
    std::cout << val;
}

int OperatorToken::getPrecedence() {
    switch (val)
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
    }
}

std::unique_ptr<Node> OperatorToken::parseToken() {
    return nullptr;
}