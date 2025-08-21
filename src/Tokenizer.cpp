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
    int i = 0;
    while (i < input.length()) {
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

    tokens = toPostFix(tokens);

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
    bool isUnary = true;
    char prev = input[curr - 1];
    if (curr != 0 && isdigit(prev) && prev != ')' && input[curr] != '-') {
        isUnary = false;
    }
    
    tokens.push_back(std::make_shared<OperatorToken>(input[curr], isUnary));

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

    auto it = std::find(std::begin(STANDARD_SYMBOLS::FUNCTIONS), std::end(STANDARD_SYMBOLS::FUNCTIONS), buffer);

    if (it != std::end(STANDARD_SYMBOLS::FUNCTIONS)) {
        tokens.push_back(std::make_shared<FunctionToken>(buffer));
    } else {
        return std::unexpected("Syntax error: Unknown function");
    }

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

std::vector<std::shared_ptr<Token>> Tokenizer::toPostFix(std::vector<std::shared_ptr<Token>> &tokens){
    std::queue<std::shared_ptr<Token>> stack;
    std::vector<std::shared_ptr<Token>> result;
    for (int i = 0; i < tokens.size(); i++) {
        std::shared_ptr<Token> currToken = tokens[i];
        TokenType tokenType = currToken->getType();

        switch (tokenType)
        {
        case NUMBER:
            result.push_back(currToken);
            /* code */
            break;
        case LBRACKET:
            stack.push(currToken);
            break;
        case RBRACKET:
            while (stack.front()->getType() != LBRACKET) {
                result.push_back(stack.front());
                stack.pop();
            }
            stack.pop();
            break;
        case FUNCTION:
        case OPERATOR:
            while (!stack.empty() && currToken->getPrecedence() <= stack.front()->getPrecedence())
            {
                result.push_back(currToken);
                stack.pop();
            }
            stack.push(currToken);
            break;
        }
    }

    while (!stack.empty()) {
        result.push_back(stack.front());
        stack.pop();
    }

    return result;
}

bool Tokenizer::isOperator(char c) {
    return std::find(std::begin(STANDARD_SYMBOLS::OPERATORS), std::end(STANDARD_SYMBOLS::OPERATORS), c) != std::end(STANDARD_SYMBOLS::OPERATORS);
}