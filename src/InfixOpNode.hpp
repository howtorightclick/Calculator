#ifndef INFIXOPNODE_HPP
#define INFIXOPNODE_HPP

#include "Node.hpp"
#include "OperatorToken.hpp"

class InfixOpNode : public Node {
public:
    InfixOpNode(char op_);

    InfixOpNode(char op_, std::unique_ptr<Node> a_, std::unique_ptr<Node> b_);

    float calculate();
private:
    char op;
    std::unique_ptr<Node> a;
    std::unique_ptr<Node> b;
};

#endif