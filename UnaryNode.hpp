#ifndef UNARYNODE_HPP
#define UNARYNODE_HPP

#include "Node.hpp"
#include "Operators.hpp"

class UnaryNode : public Node {
public:
    float calculate();
    
private:
    UnaryOperator op;
    Node *a;
};

#endif