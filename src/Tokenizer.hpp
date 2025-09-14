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
#include "BracketToken.hpp"

class Tokenizer {
    
public:
    struct Expression
    {
        std::vector<std::string> strings;
        std::vector<TokenType> types;
        std::unordered_map<int, int> bracketMap;
        int length;
    };

    inline static std::set<TokenType> allowedPredecessors[NUMTYPES] = {{START, OPERATOR}, {START, OPERATOR, FUNCTION}, {NUMBER}, {START, OPERATOR, LBRACKET}, {NUMBER, RBRACKET}};
    inline static std::set<TokenType> allowedFollowers[NUMTYPES] = {{LBRACKET}, {NUMBER, FUNCTION}, {OPERATOR, END}, {OPERATOR, END}, {NUMBER, FUNCTION}};

    Tokenizer();

    // Tokenize input string
    std::expected<std::vector<std::unique_ptr<Token>>, std::string> tokenize(std::string &input);

    // Print the list of tokens
    void printStrings(std::vector<std::unique_ptr<Token>> const &tokens);

    // Checks if the given character is a mathematical operator
    static bool isOperator(char c);

    static std::expected<int, std::string> validateTokenOrder(Expression &expression, int start, int end);
private:
    std::expected<TokenType, std::string> validateBuffer(std::string &buffer);

    std::queue<int> leftBrackets;
};

#endif