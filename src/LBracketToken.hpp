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

    int getPrecedence();

    std::expected<std::unique_ptr<Node>, std::string> parseToken(Parser &parser);
private:
    int rightBracket;
};

#endif