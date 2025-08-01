#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <vector>
#include <string>
#include <memory>

#include "Token.hpp"
#include "FunctionToken.hpp"
#include "NumberToken.hpp"
#include "OperatorToken.hpp"

class Tokenizer {
public:
    Tokenizer();

    // Tokenize input string and return a vector of tokens
    void tokenize(std::string &input);

    void printTokens();
private:
    // Finds the matching right bracket and returns its index
    int tokenizeNumber(std::string &input, int &curr);

    //int findMatchingRightBracket(std::string &input, std::vector<int> &bracketMatch, int curr);

    std::vector<std::shared_ptr<Token>> tokens;
};

#endif