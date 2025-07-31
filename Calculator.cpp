#include "Calculator.hpp"
#include "Tokenizer.hpp"

int main(int argc, char* argv[]) {
    if (argc > 2) {
        // TODO: error handling
    }
    
    Tokenizer tokenizer = Tokenizer();
    std::string equation = argv[1];
    tokenizer.tokenize(equation);

}