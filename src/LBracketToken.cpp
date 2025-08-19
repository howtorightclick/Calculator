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

std::expected<std::unique_ptr<Node>, std::string> LBracketToken::parseToken(Parser &parser) {
    TokenType prevType = parser.getPrev()->getType();
    if (prevType != OPERATOR && !parser.isFirst()) {
        return std::unexpected("Parser Error: Unexpected symbol behind left bracket");
    }

    parser.advanceToken();

    auto result = parser.parseTokens();
    if (result) {
        std::shared_ptr<Token> nextToken = parser.peek();
        if (nextToken->getType() != RBRACKET) {
            return std::unexpected("Parser Error: Missing matching ')'");
        } 
        return std::move(result.value());
    } else {
        return result;
    }



    return nullptr;
}