#ifndef BRACKET_TOKEN_HPP
#define BRACKET_TOKEN_HPP

#include <string>
#include <stack>

#include "Token.hpp"
#include "Node.hpp"

class BracketToken : public Token {
public:
    BracketToken(bool isLeft);

    //Node *toNode();

    TokenType getType() const;

    void printToken() const;

    int getPrecedence() const;

    bool isLeft() const;

    std::string getContent() const;

    void accept(Parser &parser) const override;
private:
    bool isLeft_;
};
#endif