#include <vector>
#include <cmath>
#include <iostream>
#include <memory>
#include <expected>
#include <set>
#include <print>

#include "Tokenizer.hpp"

Tokenizer::Tokenizer() {

}

std::expected<int, std::string> Tokenizer::tokenize(std::string &input) {
    std::set<char> operators = {};
    int i = 0;
    while (i < input.length()) {
        std::cout << i << std::endl;
        if (isdigit(input[i])) {
            auto result = tokenizeNumber(input, i);
            if (result) {
                i = result.value();
            } else {
                return result;
            }
        } else if (isOperator(input[i])) {
            i = tokenizeOperator(input, i);
        } else if (isalpha(input[i])) {
            auto result = tokenizeFunction(input, i);
            if (result) {
                i = result.value();
            } else {
                return result;
            }
        } else if (input[i] == '(') {
            i = tokenizeLeftBracket(input, i);
        } else if (input[i] == ')') {
            auto result = tokenizeRightBracket(input, i);
            if (result) {
                i = result.value();
            } else {
                return result;
            }
        } else {
            std::unexpected("Syntax error: Unexpected symbol");
        }
    }

    return 0;
}

std::expected<int, std::string> Tokenizer::tokenizeNumber(const std::string &input, int &curr) noexcept {
    int numDecimalMarkers = 0;
    int index = curr;

    //float res = 0;
    std::string buffer = "";
    while (index < input.length()) {
        
        if (isdigit(input[index])) {
            buffer.push_back(input[index]);
        } else if (input[index] == '.') {
            numDecimalMarkers += 1;
            if (numDecimalMarkers > 1) {
                return std::unexpected("Syntax error: More than one decimal markers");
            } else {
                buffer.push_back(input[index]);
            }
            //isDecimal = true;
        } else {
            break;
        }
        index++;
    }

    tokens.push_back(std::make_shared<NumberToken>(std::stof(buffer)));
    return index; 
}

int Tokenizer::tokenizeOperator(const std::string &input, const int curr) {
    tokens.push_back(std::make_shared<OperatorToken>(input[curr]));

    return curr + 1;
}

std::expected<int, std::string> Tokenizer::tokenizeFunction(const std::string &input, int &curr) {
    std::string buffer = "";
    int i = curr;
    while (i < input.length()) {
        if (isalpha(input[i])) {
            buffer.push_back(input[i]);
        } else {
            break;
        }
        i++;
    }

    char next = input[i];

    if (next != '(') {
        return std::unexpected("Syntax error: Missing bracket after function");
    }

    Function func;
    if (buffer == "sin") {
        func = SIN;
    } else if (buffer == "cos") {
        func = COS;
    } else if (buffer == "tan") {
        func = TAN;
    } else if (buffer == "sinh") {
        func = SINH;
    } else if (buffer == "cosh") {
        func = COSH;
    } else if (buffer == "tanh") {
        func = TANH;
    } else {
        return std::unexpected("Syntax error: Unknown function");
    }

    tokens.push_back(std::make_shared<FunctionToken>(func));

    return i;
}

int Tokenizer::tokenizeLeftBracket(const std::string &input, const int curr) {
    tokens.push_back(std::make_shared<LBracketToken>());
    Tokenizer::leftBrackets.push(tokens.size() - 1);
    return curr + 1;
}

std::expected<int, std::string> Tokenizer::tokenizeRightBracket(const std::string &input, const int curr) {
    if (Tokenizer::leftBrackets.empty()) {
        return std::unexpected("Syntax error: Mismatched brackets");
    }
    
    int left = Tokenizer::leftBrackets.front();
    Tokenizer::bracketMap[left] = curr;
    Tokenizer::leftBrackets.pop();
    tokens.push_back(std::make_shared<RBracketToken>());
    return curr + 1;
}

void Tokenizer::printTokens() {
    for (auto &token: tokens) {
        token->printToken();
        std::cout << " | ";
    }

    std::cout << '\n';
}

bool Tokenizer::isOperator(char c) {
    return std::find(OPERATORS, OPERATORS + 5, c) != OPERATORS + 5;
}