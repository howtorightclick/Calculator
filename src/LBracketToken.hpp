#ifndef L_BRACKET_TOKEN_HPP
#define L_BRACKET_TOKEN_HPP

#include "Token.hpp"

class LBracketToken : public Token {
public:
    LBracketToken();

    //Node *toNode();

    TokenType getType();

    void printToken();

    void setRightBracket(int i);
private:
    int rightBracket;
};

#endif