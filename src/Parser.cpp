#include <queue>
#include <expected>

#include "Parser.hpp"
#include "FloatNode.hpp"

Parser::Parser() {

}

std::expected<std::unique_ptr<Node>, std::string> Parser::parseTokens() {
    const std::shared_ptr<Token> curr = peek();
    if (curr == nullptr) {
        return std::unexpected("Parser Error: Unexpected end of input");
    }

    return curr->parseToken(*this);
}

std::expected<std::unique_ptr<Node>, std::string> Parser::parseTokens(size_t end) {
    std::unique_ptr<Node> root = nullptr;
    while (current < end) {
        std::shared_ptr<Token> currToken = peek();
        auto result = currToken->parseToken(*this);
        if (result) {
            root = std::move(result.value());
        } else {
            return result;
        }
    }
}

void setTokenList(std::vector<std::shared_ptr<Token>> tokens);


void setBracketMap(std::unordered_map<int, int> bracketMap);


void Parser::advanceToken() {
    if (current < tokens.size()) {
        current++;
    }
}


std::shared_ptr<Token> Parser::peek() {
    if (current >= tokens.size()) {
        return nullptr;
    } else {
        return tokens[current];
    }
}

Token *getPrev();

Token *getNext();

bool isFirst();