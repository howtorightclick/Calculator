#include <iostream>
#include <memory>
#include <queue>

#include "FunctionToken.hpp"
#include "FunctionNode.hpp"

FunctionToken::FunctionToken(std::string function):
function(function)
{
}

/*Node *FunctionToken::toNode() {
    // TODO: convert token into node
    return nullptr;
}*/

TokenType FunctionToken::getType() const {
    return FUNCTION;
}

void FunctionToken::printToken() const {
    std::cout << function;
}

int FunctionToken::getPrecedence() const {
    return 4;
}

std::string FunctionToken::getContent() const {
    return function;
}

std::unique_ptr<FunctionToken> FunctionToken::clone() const {
    return std::make_unique<FunctionToken>(function);
}

void FunctionToken::accept(Parser &parser) const {
    parser.process(*this);
}