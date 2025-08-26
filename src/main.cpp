#include <iostream>

#include "Tokenizer.hpp"

int main(int argc, char* argv[]) {
    if (argc > 2) {
        // TODO: error handling
    }
    
    Tokenizer tokenizer = Tokenizer();

    std::string input;
    std::getline(std::cin, input);
    auto result = tokenizer.tokenize(input);
    if (!result) {
        return -1;
    }

    Tokenizer::TokenizedExpression expression = result.value();

    tokenizer.printStrings(expression.strings);



    return 0;
}