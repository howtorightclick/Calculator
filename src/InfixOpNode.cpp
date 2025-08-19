#include "InfixOpNode.hpp"

InfixOpNode::InfixOpNode(char op_): 
    op (op_)
{
}

InfixOpNode::InfixOpNode(char op_, std::unique_ptr<Node> a_, std::unique_ptr<Node> b_): 
    op (op_)
{
    a = std::move(a_);
    b = std::move(b_);
}

float InfixOpNode::calculate() {
    return 0;
}

