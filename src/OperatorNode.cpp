#include <iostream>

#include "OperatorNode.hpp"

OperatorNode::OperatorNode(char op_): 
    op (op_)
{
}

OperatorNode::OperatorNode(char op_, std::unique_ptr<Node> a_, std::unique_ptr<Node> b_): 
    op (op_)
{
    a = std::move(a_);
    b = std::move(b_);
}

void OperatorNode::inOrderPrint(std::string &prefix, bool isLeft) const {
    std::cout << prefix;
    std::cout << (isLeft ? "├──" : "└──");
    std::cout << op << std::endl;

    std::string newPrefix = prefix + (isLeft ? "│   " : "    ");
    a->inOrderPrint(newPrefix, true);
    b->inOrderPrint(newPrefix, false);
}

float OperatorNode::calculate() {

    // Ensure that a and b are compatible types

    switch (op)
    {
    case '+':
        // Check types
        return a->calculate() + b->calculate();
        break;
    case '-':
        return a->calculate() + b->calculate();
    
    default:
        break;
    }

    return 0;
}

