#ifndef INFIXOPNODE_HPP
#define INFIXOPNODE_HPP

#include "Node.hpp"
#include "Operators.hpp"

class InfixOpNode : public Node {
public:
    InfixOpNode(InfixOperator op);

    float calculate();
    
    void insertA(Node *a);

    void insertB(Node *b);
private:
    InfixOperator op_;
    Node *a_;
    Node *b_;
};

#endif