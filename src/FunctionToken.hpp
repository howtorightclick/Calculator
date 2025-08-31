#ifndef FUNCTION_TOKEN_HPP
#define FUNCTION_TOKEN_HPP

#include <string>

#include "Term.hpp"

class FunctionToken : public Term {
public:
    FunctionToken(std::string function);

    //Node *toNode();

    TokenType getType();

    void printToken();

    int getPrecedence();

    std::unique_ptr<Node> parseToken();
private:
    std::string function;
};
#endif