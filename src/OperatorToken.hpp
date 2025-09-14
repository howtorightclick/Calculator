#ifndef OPERATOR_TOKEN_HPP
#define OPERATOR_TOKEN_HPP

#include "Token.hpp"

class OperatorToken : public Token {
public:
    OperatorToken(std::string _content, bool _unary);

   //Node *toNode();

    TokenType getType() const;

    void printToken() const;

    int getPrecedence() const override;

    bool isRightAssociative() const;

    std::string getContent() const;

    std::unique_ptr<OperatorToken> clone() const;

    void accept(Parser &parser) const override;
private:

    bool isUnary;
    int numArgs;
    std::string content;
};

#endif