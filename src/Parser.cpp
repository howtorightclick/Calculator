#include <queue>
#include <expected>

#include "Parser.hpp"
#include "FloatNode.hpp"

Parser::Parser() {

}

std::expected<std::unique_ptr<Node>, std::string> Parser::parseTokens(Tokenizer::TokenizedExpression expression) {
    
}
