#ifndef NUMBER_TOKEN_HPP
#define NUMBER_TOKEN_HPP

#include "Token.hpp"

class NumberToken : public Token {
public:
    NumberToken(float val);

    //Node *toNode();

    TokenType getType();

    void printToken();

    std::expected<std::unique_ptr<Node>, std::string> parseToken(Parser &parser);
private:
    float val;
};

#endif