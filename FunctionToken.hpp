#ifndef FUNCTION_TOKEN_HPP
#define FUNCTION_TOKEN_HPP

#include <string>

#include "Token.hpp"

class FunctionToken : public Token {
public:
    FunctionToken(Function function);

    Node *toNode();

    TokenType getType();

    void printToken();
private:
    Function function;
};

#endif