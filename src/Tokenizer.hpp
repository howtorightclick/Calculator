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
    struct TokenizedExpression
    {
        std::vector<std::string> strings;
        std::vector<TokenType> types;
        std::unordered_map<int, int> bracketMap;
    };

    Tokenizer();

    // Tokenize input string
    std::expected<TokenizedExpression, std::string> tokenize(std::string &input);

    // Print the list of tokens
    void printStrings(std::vector<std::string> &tokens);

    // Checks if the given character is a mathematical operator
    static bool isOperator(char c);
private:
    std::expected<TokenType, std::string> validateBuffer(std::string &buffer);

    /// @brief Converts the token vector into postfix order.
    std::vector<std::shared_ptr<Term>> toPostFix(std::string &input);

    std::expected<bool, std::string> validateTokenOrder(std::vector<std::string> &strings);

    std::queue<int> leftBrackets;
};

#endif