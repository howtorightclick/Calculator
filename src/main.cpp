#include <iostream>
#include <map>
#include <any>
#include <unordered_map>

#include "Tokenizer.hpp"
#include "Parser.hpp"

int main(int argc, char* argv[]) {
    if (argc > 2) {
        // TODO: error handling
    }
    
    Tokenizer tokenizer = Tokenizer();

    std::string input;
    std::getline(std::cin, input);
    auto result = tokenizer.tokenize(input);
    if (!result) {
        std::cout << result.error();
        return -1;
    }

    std::vector<std::unique_ptr<Token>> tokens = std::move(result.value());
    //Tokenizer::validateTokenOrder(expression, 0, expression.length);
    tokenizer.printStrings(tokens);
    std::cout << tokens.size();

    Parser parser = Parser();
    std::unique_ptr<Node> root = std::move(parser.parseTokens(std::move(tokens)));
    std::string prefix = "";
    root->inOrderPrint(prefix, false);
    
    std::unordered_map<std::string, std::any> mathFunctions;

    std::unordered_map<std::string, std::any> otherFunctions;

    return 0;
}