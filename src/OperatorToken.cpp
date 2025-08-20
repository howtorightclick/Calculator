#include <iostream>

#include "OperatorToken.hpp"
#include "InfixOpNode.hpp"

OperatorToken::OperatorToken(char val) {
    OperatorToken::val = val;
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
        return 2;
    case '/':
        return 2;
    case '+':
        return 1;
    case '-':
        return 1;
    }
}

std::expected<std::unique_ptr<Node>, std::string> OperatorToken::parseToken(Parser &parser) {
    return nullptr;
}