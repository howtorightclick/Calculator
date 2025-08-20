#ifndef R_BRACKET_TOKEN_HPP
#define R_BRACKET_TOKEN_HPP

#include "Token.hpp"

class RBracketToken : public Token {
public:
    RBracketToken();

    //Node *toNode();

    TokenType getType();

    void printToken();

    int getPrecedence();

    std::expected<std::unique_ptr<Node>, std::string> parseToken(Parser &parser);
private:

};

#endif