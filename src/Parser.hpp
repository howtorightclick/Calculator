#ifndef PARSER_HPP
#define PARSER_HPP

#include <memory>
#include <unordered_map>
#include <vector>
#include <queue>

#include "Node.hpp"
#include "Token.hpp"

class Parser {
public:
    Parser();

    std::expected<std::unique_ptr<Node>, std::string> parseTokens();

    std::expected<std::unique_ptr<Node>, std::string> parseTokens(size_t end);

    // Sets the token list
    void setTokenList(std::vector<std::shared_ptr<Token>> tokens);

    // Sets the bracket map
    void setBracketMap(std::unordered_map<int, int> bracketMap);

    // Advances the current token by one
    void advanceToken();

    // Peeks at the current token without consuming it
    std::shared_ptr<Token> peek();

    // Returns a pointer to the previous token in the sequence
    std::shared_ptr<Token> getPrev();

    // Returns a pointer to the next token in the sequence
    std::shared_ptr<Token> getNext();

    // Returns true if the current token is the first token in the sequence
    bool isFirst();

private:
    std::vector<std::shared_ptr<Token>> tokens;
    
    std::unordered_map<int, int> bracketMap;

    size_t current;

    std::queue<std::unique_ptr<Node>> queue;
};

#endif