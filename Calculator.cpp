#include <iostream>

#include "Calculator.hpp"
#include "Tokenizer.hpp"

int main(int argc, char* argv[]) {
    if (argc > 2) {
        // TODO: error handling
    }
    
    Tokenizer tokenizer = Tokenizer();

    std::string input;
    std::cin >> input;

    tokenizer.tokenize(input);

    tokenizer.printTokens();

    return 0;
}