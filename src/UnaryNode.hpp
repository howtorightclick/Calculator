#ifndef UNARYNODE_HPP
#define UNARYNODE_HPP

#include "Node.hpp"
#include "OperatorToken.hpp"

class UnaryNode : public Node {
public:
    float calculate();
    
private:
    OperatorToken op;
    Node *a;
};

#endif