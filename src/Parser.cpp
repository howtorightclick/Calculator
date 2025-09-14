#include <queue>
#include <expected>
#include <iostream>

#include "Parser.hpp"
#include "FloatNode.hpp"
#include "Node.hpp"
#include "OperatorNode.hpp"
#include "FunctionNode.hpp"
#include "NumberToken.hpp"
#include "FunctionToken.hpp"
#include "OperatorToken.hpp"
#include "BracketToken.hpp"

Parser::Parser() {

}

void Parser::process(const NumberToken &token) {
    //std::cout << "test";
    nodeStack.push(std::make_unique<FloatNode>(token.getVal()));
}

void Parser::process(const FunctionToken &token) {
    operatorStack.emplace(token.clone());
}

void Parser::process(const OperatorToken &token) {
    const Token* top = operatorStack.top().get();
    int topPrec = top->getPrecedence();
    int currPrec = token.getPrecedence();
    TokenType currType = top->getType();

    while (
        !operatorStack.empty() && currType != LBRACKET
        && ((!token.isRightAssociative() && topPrec >= currPrec)
            || (token.isRightAssociative() && topPrec > currPrec))) 
    {
        buildNodeFromStack();
    }

    
}

void Parser::process(const BracketToken &token) {
    if (token.isLeft()) {
        operatorStack.push(std::make_unique<BracketToken>(token.isLeft()));
    } else {
        while (!operatorStack.empty() && !operatorStack.top()->getType() != LBRACKET) {
            buildNodeFromStack();
        }

        operatorStack.pop();

        if (!operatorStack.empty() && operatorStack.top()->getType() == FUNCTION) {
            buildNodeFromStack();
        }
    }
}

void Parser::buildNodeFromStack() {
    std::unique_ptr<Token> op = std::move(operatorStack.top());
    operatorStack.pop();

    if (op->getType() == OPERATOR) {
        if (nodeStack.size() < 2) {
            // Error
        }

        std::unique_ptr<Node> right = std::move(nodeStack.top());
        nodeStack.pop();
        std::unique_ptr<Node> left = std::move(nodeStack.top());

        //std::unique_ptr<Node> newNode = std::make_unique<OperatorNode>(op->getContent()[0], std::move(left), std::move(right));
        nodeStack.push(std::move(std::make_unique<OperatorNode>(op->getContent()[0], std::move(left), std::move(right))));
    } else if (op->getType() == FUNCTION) {
        //std::unique_ptr<Node> child = std::move(nodeStack.top());
        nodeStack.pop();

        std::unique_ptr<Node> newNode = std::make_unique<FunctionNode>(op->getContent(), std::move(nodeStack.top()));
        nodeStack.push(std::move(newNode));
    }

}

std::unique_ptr<Node> Parser::parseTokens(std::vector<std::unique_ptr<Token>> tokens) {
    for (int i = 0; i < tokens.size(); i++) {
        tokens[i]->accept(*this);
    }

    std::unique_ptr<Node> root = std::move(nodeStack.top());
    nodeStack.pop();
    return std::move(root);
}