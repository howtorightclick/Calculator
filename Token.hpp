#ifndef TOKEN_HPP
#define TOKEN_HPP

#include "Node.hpp"

enum TokenType {
    SIN,
    COS,
    TAN,
    COTAN,
    SINH,
    COSH,
    TANH,
    LBRACKET,
    RBRACKET,
    INTEGER,
    DECIMAL,
    DOTPRODUCT,
    ADDITION,
    DIVISION,
    MULTIPLICATION,
    SUBTRACTION
};

class Token {
public:
    virtual Node *toNode() = 0;
    virtual bool isOperator() = 0;
    virtual bool isFunction() = 0;
private:
};

#endif