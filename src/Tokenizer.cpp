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

std::expected<Tokenizer::TokenizedExpression, std::string> Tokenizer::tokenize(std::string &input) {
    // Read until space or operator
    Tokenizer::TokenizedExpression expression;
    std::vector<std::string> tokens;
    expression.types.push_back(START);
    std::queue<int> leftBracketStack;
    std::string buffer;
    for (int i = 0; i < input.size(); i++) {

        if (input[i] == ' ' || isOperator(input[i]) || input[i] == '(' || input[i] == ')') {
            auto result = validateBuffer(buffer);
            if (!result) {
                return std::unexpected(result.error());
            }

            if (result.value() == ERROR) {
                return std::unexpected("Error: unexpected symbol at " + input);
            }
            expression.strings.push_back(buffer);
            expression.types.push_back(result.value());
            buffer = "";

            if (input[i] != ' ') {
                expression.strings.push_back(std::string(1, input[i]));
                expression.types.push_back(OPERATOR);
            }

            if (input[i] == '(') {
                leftBracketStack.push(expression.strings.size() - 1);
                expression.types.push_back(LBRACKET);
            } else if (input[i] == ')') {
                if (leftBracketStack.size() == 0) {
                    return std::unexpected("Error: unexpected symbol in " + input);
                }
                expression.bracketMap[leftBracketStack.front()] = expression.strings.size() - 1;
                leftBracketStack.pop();
                expression.types.push_back(RBRACKET);
            }
        } else {
            buffer.push_back(input[i]);
        }
    }

    if (leftBracketStack.size() != 0) {
        return std::unexpected("Error: unexpected symbol in " + input);
    }

    auto result = validateBuffer(buffer);
    if (!result) {
        return std::unexpected(result.error());
    }
    expression.strings.push_back(buffer);
    expression.types.push_back(END);
    expression.length = expression.strings.size();
    return expression;
}

std::expected<TokenType, std::string> Tokenizer::validateBuffer(std::string &buffer) {
    if (buffer.size() == 0) {
        return ERROR;
    }
    // Buffer either contains a number or a function
    if (isdigit(buffer[0])) {
        int numDecimalPoints = 0;
        for (int i = 0; i < buffer.size(); i++) {
            if (buffer[i] == '.') {
                numDecimalPoints++;
            } else if (isalpha(buffer[i])) {
                return std::unexpected("Error: unexpected symbol in \'" + buffer + "\'");
            }

            if (numDecimalPoints > 1) {
                return std::unexpected("Error: unexpected numerical constant in \'" + buffer + "\'");
            }
        }
        return NUMBER;
    } else {
        auto it = std::find(std::begin(STANDARD_SYMBOLS::FUNCTIONS), std::end(STANDARD_SYMBOLS::FUNCTIONS), buffer);

        if (it == std::end(STANDARD_SYMBOLS::FUNCTIONS)) {
           return std::unexpected("Error: object \'" + buffer + "\' not found");
        }

        return FUNCTION;
    }

}

std::expected<int, std::string> Tokenizer::validateTokenOrder(Tokenizer::TokenizedExpression &expression, int start, int end) {
    for (int i = start; i < end; i++) {
        TokenType curr = expression.types[i];
        if (i == start && !Tokenizer::allowedPredecessors[curr].contains(START)) {
            return std::unexpected("Error: unexpected symbol");
        } else if (i == end - 1 && !Tokenizer::allowedFollowers[curr].contains(END)) {
            return std::unexpected("Error: unexpected symbol");
        } else {
            TokenType prev = expression.types[i - 1];
            TokenType next = expression.types[i + 1];

            if (!Tokenizer::allowedFollowers[curr].contains(next)) {
                return std::unexpected("");
            }

            if (!Tokenizer::allowedPredecessors[curr].contains(prev)) {
                return std::unexpected("");
            }

            if (curr == LBRACKET) {
                auto res = validateTokenOrder(expression, i + 1, expression.bracketMap[i]);
                if (!res) {
                    return res;
                } else {
                    i = res.value();
                }
            }
        }
    }

    return end;
}


void Tokenizer::printStrings(std::vector<std::string> &strings) {
    for (auto str: strings) {
        std::cout << str << " ";
    }

    std::cout << std::endl;
}

bool Tokenizer::isOperator(char c) {
    return std::find(std::begin(STANDARD_SYMBOLS::OPERATORS), std::end(STANDARD_SYMBOLS::OPERATORS), c) != std::end(STANDARD_SYMBOLS::OPERATORS);
}