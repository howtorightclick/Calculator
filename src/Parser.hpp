#ifndef PARSER_HPP
#define PARSER_HPP

#include <memory>
#include <unordered_map>
#include <vector>
#include <queue>

#include "Node.hpp"
#include "Token.hpp"
#include "Tokenizer.hpp"

class Parser {
public:
    Parser();

    std::expected<std::unique_ptr<Node>, std::string> parseTokens(Tokenizer::TokenizedExpression expression);

private:

};

#endif