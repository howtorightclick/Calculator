#ifndef NUMBER_TOKEN_HPP
#define NUMBER_TOKEN_HPP

#include "Token.hpp"

class NumberToken : public Token {
public:
    NumberToken(float val);

    //Node *toNode();

    TokenType getType();

    void printToken();
private:
    float val;
};

#endif