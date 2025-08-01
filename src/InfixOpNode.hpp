#ifndef INFIXOPNODE_HPP
#define INFIXOPNODE_HPP

#include "Node.hpp"
#include "OperatorToken.hpp"

class InfixOpNode : public Node {
public:
    InfixOpNode(OperatorToken op);

    float calculate();
    
    void insertA(Node *a);

    void insertB(Node *b);
private:
    OperatorToken op_;
    Node *a_;
    Node *b_;
};

#endif