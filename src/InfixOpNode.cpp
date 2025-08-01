#include "InfixOpNode.hpp"

InfixOpNode::InfixOpNode(OperatorToken op): 
    op_ (op),
    a_ (nullptr),
    b_ (nullptr)
{
}

void InfixOpNode::insertA(Node *a) {
    a_ = a;
}

void InfixOpNode::insertB(Node *b) {
    b_ = b;
}

float InfixOpNode::calculate() {
    return 0;
}

