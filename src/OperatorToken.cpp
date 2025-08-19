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

std::expected<std::unique_ptr<Node>, std::string> OperatorToken::parseToken(Parser &parser) {
    parser.advanceToken();

    // TODO: Error checking

    return std::make_unique<InfixOpNode>(val);
}