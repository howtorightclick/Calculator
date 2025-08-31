#include <queue>
#include <expected>

#include "Parser.hpp"
#include "FloatNode.hpp"

Parser::Parser() {

}

std::expected<std::unique_ptr<Node>, std::string> Parser::parseTokens(std::queue<std::unique_ptr<Node>> stack) {
    return nullptr;
}

std::expected<std::unique_ptr<Node>, std::string> Parser::parseTokens(size_t end) {
    return nullptr;
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

void Parser::pushStack(std::unique_ptr<Node> node) {
    queue.push(std::move(node));
}

std::unique_ptr<Node> Parser::popStack() {
    return std::move(queue.front());
}