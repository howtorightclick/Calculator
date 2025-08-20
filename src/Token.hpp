#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <set>
#include <memory>
#include <expected>

#include "Node.hpp"
#include "Parser.hpp"

//#include "Node.hpp"
namespace STANDARD_SYMBOLS {
    inline constexpr char OPERATORS[5] = {'+', '-', '/', '*', '^'};


    inline constexpr const char* FUNCTIONS[7] = {
        "sin",
        "cos",
        "tan",
        "cotan",
        "sinh",
        "cosh",
        "tanh"
    };
}


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
    virtual ~Token() = default;

    virtual TokenType getType() = 0;

    virtual void printToken() = 0;

    virtual int getPrecedence() = 0;

    virtual std::expected<std::unique_ptr<Node>, std::string> parseToken(Parser &parser) = 0;
};

#endif