#include <vector>

#include "Tokenizer.hpp"
#include "Node.hpp"

std::vector<TokenType> Tokenizer::tokenize(std::string &input) {
    std::string buffer = "";
    std::vector<TokenType> tokens;
    for (int i = 0; i < input.length(); i++) {
        if (isdigit(input[i])) {
            i = tokenizeNumber(tokens, input, i);
            // TODO: error checking 
        }
    }
}

int findMatchingRightBracket(std::string &input, std::vector<int> &bracketMatch, int curr) {

}

int tokenizeNumber(std::vector<TokenType> &tokens, std::string &input, int &curr) {
    bool isLastDigit = false;
    int numDecimalPoints = 0;
    int index = curr;
    std::string buffer;
    while (!isLastDigit && index < input.length()) {
        if (numDecimalPoints > 1) {
            return -1;
        }

        if (isdigit(input[index]) || input[index] == '.') {
            buffer.push_back(input[index]);
        } else {
            isLastDigit = true;
        }
        index++;
    }

    // TODO: push to tokens
    
    return index; 
}