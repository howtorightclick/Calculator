#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include "Node.hpp"
#include <string>
#include "Token.hpp"

class Tokenizer {
public:
    // Tokenize input string and return a vector of tokens
    std::vector<TokenType> tokenize(std::string &input);

private:
    // Finds the matching right bracket and returns its index
    int tokenizeNumber(std::vector<TokenType> &tokens, std::string &input, int curr);

    int findMatchingRightBracket(std::string &input, std::vector<int> &bracketMatch, int curr);
};

#endif