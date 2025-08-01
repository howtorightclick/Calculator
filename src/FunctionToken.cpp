#include "FunctionToken.hpp"

FunctionToken::FunctionToken(Function function) {
    FunctionToken::function = function;
}

/*Node *FunctionToken::toNode() {
    // TODO: convert token into node
    return nullptr;
}*/

TokenType FunctionToken::getType() {
    return FUNCTION;
}

void FunctionToken::printToken() {
    
}