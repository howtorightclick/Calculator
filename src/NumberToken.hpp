#ifndef NUMBER_TOKEN_HPP
#define NUMBER_TOKEN_HPP

#include "Term.hpp"

class NumberToken : public Term {
public:
    NumberToken(float val);

    //Node *toNode();

    TokenType getType();

    void printToken();

    int getPrecedence();

    std::unique_ptr<Node> parseToken();
private:
    float val;
};

#endif