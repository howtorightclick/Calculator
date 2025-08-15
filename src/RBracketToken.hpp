#ifndef R_BRACKET_TOKEN_HPP
#define R_BRACKET_TOKEN_HPP

#include "Token.hpp"

class RBracketToken : public Token {
public:
    RBracketToken();

    //Node *toNode();

    TokenType getType();

    void printToken();
private:

};

#endif