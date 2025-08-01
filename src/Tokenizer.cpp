#include <vector>
#include <cmath>
#include <iostream>
#include <memory>

#include "Tokenizer.hpp"

Tokenizer::Tokenizer() {

}

void Tokenizer::tokenize(std::string &input) {
    TokenType prev = NUMBER;

    for (int i = 0; i < input.length(); i++) {
        if (isdigit(input[i])) {
            i = tokenizeNumber(input, i);
            //TODO: error checking 

            prev = NUMBER;
        } else if (isalpha(input[i])) {
            if (prev != OPERATOR) {
                //TODO: throw invalid syntax error
            }

            
        }
    }
}

int Tokenizer::tokenizeNumber(std::string &input, int &curr) {
    bool isLastDigit = false, isDecimal = false;
    int numDecimalPoints = 0;
    int index = curr;

    float res = 0;

    while (!isLastDigit && index < input.length()) {
        if (numDecimalPoints > 1) {
            return -1;
        }
        if (isdigit(input[index])) {
            int digitShift = 1;
            if (isDecimal) {
                digitShift = pow(10, (curr - index) * -1);
            } else {
                digitShift = pow(10, curr - index);
            }
            res += input[index] * digitShift;

        } else if (input[index] == '.') {
            isDecimal = true;
        } else {
            isLastDigit = true;
        }
        index++;
    }

    tokens.push_back(std::make_shared<NumberToken>(res));
    return index; 
}

void Tokenizer::printTokens() {
    for (auto &token: tokens) {
        token->printToken();
        std::cout << " | ";
    }

    std::cout << '\n';
}