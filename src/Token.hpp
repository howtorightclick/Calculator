#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <set>
#include <memory>
#include <expected>
#include <stack>

#include "Parser.hpp"

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

enum TokenType {
    FUNCTION,
    LBRACKET,
    RBRACKET,
    NUMBER,
    OPERATOR,
    NUMTYPES,
    ERROR,
    START,
    END
};

class Token {
public:
    //virtual Node *toNode() = 0;
    Token() = default;

    virtual TokenType getType() const = 0;

    virtual int getPrecedence() const = 0;

    virtual std::string getContent() const = 0;

    virtual void printToken() const = 0;

    virtual void accept(Parser &parser) const = 0;
private:
    std::string content;
};

#endif