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
    return 0;
}

