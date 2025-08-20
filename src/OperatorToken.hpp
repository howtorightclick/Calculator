#ifndef OPERATOR_TOKEN_HPP
#define OPERATOR_TOKEN_HPP

#include "Token.hpp"

class OperatorToken : public Token {
public:
    OperatorToken(char val);

   //Node *toNode();

    TokenType getType();

    void printToken();

    int getPrecedence();

    std::expected<std::unique_ptr<Node>, std::string> parseToken(Parser &parser);
private:
    char val;
};

#endif