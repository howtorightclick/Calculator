#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <vector>
#include <string>
#include <memory>
#include <expected>
#include <queue>
#include <unordered_map>

#include "Token.hpp"
#include "FunctionToken.hpp"
#include "NumberToken.hpp"
#include "OperatorToken.hpp"
#include "LBracketToken.hpp"
#include "RBracketToken.hpp"

class Tokenizer {
public:
    Tokenizer();

    // Tokenize input string
    std::expected<int, std::string> tokenize(std::string &input);

    // Print the list of tokens
    void printTokens();

    // Checks if the given character is a mathematical operator
    static bool isOperator(char c);
private:
    // Creates a number token from the input string starting at curr and returns the new index.
    // Guarantees that the resulting number is valid.
    // Returns the new index.
    std::expected<int, std::string> tokenizeNumber(const std::string &input, int &curr) noexcept;

    // Creates an operator token from the input string starting at curr.
    // Gurantees that expression is well formed.
    int tokenizeOperator(const std::string &input, const int curr);
    //int findMatchingRightBracket(std::string &input, std::vector<int> &bracketMatch, int curr);

    // Creates a function token from the input string starting at curr and returns the new index.
    // Guarantees that expression is well formed.
    // Returns the new index.
    std::expected<int, std::string> tokenizeFunction(const std::string &input, int &curr);

    // Creates a left bracket token from input string at curr and pushes its index onto a queue.
    // Guarantees that expression is well formed.
    // Returns the new index.
    int tokenizeLeftBracket(const std::string &input, const int curr);

    /// @brief Converts the token vector into postfix order.
    std::vector<std::shared_ptr<Token>> toPostFix(std::vector<std::shared_ptr<Token>> &tokens);

    std::expected<int, std::string> tokenizeRightBracket(const std::string &input, const int curr);

    std::vector<std::shared_ptr<Token>> tokens;

    std::queue<int> leftBrackets;

    std::unordered_map<int, int> bracketMap;
};

#endif