#ifndef FUNCTION_TOKEN_HPP
#define FUNCTION_TOKEN_HPP

#include <string>

#include "Token.hpp"

class FunctionToken : public Token {
public:
    FunctionToken(std::string function);

    //Node *toNode();

    TokenType getType();

    void printToken();

    std::expected<std::unique_ptr<Node>, std::string> parseToken(Parser &parser);
private:
    std::string function;
};
#endif