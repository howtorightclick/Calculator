#ifndef TERM_HPP
#define TERM_HPP

#include "Token.hpp"

class Term : public Token {
public:
    virtual std::unique_ptr<Node> parseToken() = 0;
};

#endif