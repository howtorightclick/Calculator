#ifndef NUMBER_TOKEN_HPP
#define NUMBER_TOKEN_HPP

#include "Token.hpp"

class NumberToken : public Token {
public:
    NumberToken(float val);

    //Node *toNode();

    TokenType getType() const;

    void printToken() const;

    int getPrecedence() const;

    float getVal() const;

    std::string getContent() const;

    void accept(Parser &parser) const override;
private:
    float val;
};

#endif