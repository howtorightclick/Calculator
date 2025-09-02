#ifndef OPERATOR_TOKEN_HPP
#define OPERATOR_TOKEN_HPP

#include "Token.hpp"

class OperatorToken : public Token {
public:
    OperatorToken(char _val, bool _unary);

   //Node *toNode();

    TokenType getType();

    void printToken();

    int getPrecedence();

    std::unique_ptr<Node> parseToken();
private:
    char val;
    bool isUnary;
};

#endif