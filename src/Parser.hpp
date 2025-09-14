#ifndef PARSER_HPP
#define PARSER_HPP

#include <memory>
#include <unordered_map>
#include <vector>
#include <stack>

#include "Node.hpp"

class Token;
class NumberToken;
class OperatorToken;
class FunctionToken;
class BracketToken;

class Parser {
public:
    Parser();

    std::unique_ptr<Node> parseTokens(std::vector<std::unique_ptr<Token>> tokens);

    void process(const NumberToken &token);

    void process(const OperatorToken &token);

    void process(const FunctionToken &token);

    void process(const BracketToken &token);

    static void printBinaryTree();

private:
    void buildNodeFromStack();

    std::stack<std::unique_ptr<Token>> operatorStack;
    std::stack<std::unique_ptr<Node>> nodeStack;
};

#endif