#ifndef OPERATOR_TOKEN_HPP
#define OPERATOR_TOKEN_HPP

#include "Token.hpp"

class OperatorToken : public Token {
public:
    OperatorToken(char val);

   //Node *toNode();

    TokenType getType();

    void printToken();
private:
    char val;
};

#endif