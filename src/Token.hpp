#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <set>

//#include "Node.hpp"

inline constexpr char OPERATORS[5] = {'+', '-', '/', '*', '^'};

enum Function {
    SIN,
    COS,
    TAN,
    COTAN,
    TANH,
    SINH,
    COSH
};

enum TokenType {
    FUNCTION,
    LBRACKET,
    RBRACKET,
    NUMBER,
    DOTPRODUCT,
    OPERATOR
};

class Token {
public:
    //virtual Node *toNode() = 0;

    virtual TokenType getType() = 0;

    virtual void printToken() = 0;
};

#endif