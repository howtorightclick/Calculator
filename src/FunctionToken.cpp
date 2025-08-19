#include <iostream>

#include "FunctionToken.hpp"
#include "UnaryNode.hpp"

FunctionToken::FunctionToken(std::string function) {
    FunctionToken::function = function;
}

/*Node *FunctionToken::toNode() {
    // TODO: convert token into node
    return nullptr;
}*/

TokenType FunctionToken::getType() {
    return FUNCTION;
}

void FunctionToken::printToken() {
    std::cout << function;
}

std::expected<std::unique_ptr<Node>, std::string> FunctionToken::parseToken(Parser &parser) {

    Token *prev = parser.getPrev();
    TokenType prevType = prev->getType();
    if (prevType != OPERATOR && prevType != LBRACKET && !parser.isFirst()) {
        return std::unexpected("Parser Error: Previous token cannot be a right bracket or number");
    }

    return std::make_unique<UnaryNode>(function);
}