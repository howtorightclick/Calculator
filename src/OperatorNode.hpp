#ifndef INFIXOPNODE_HPP
#define INFIXOPNODE_HPP

#include "Node.hpp"
#include "OperatorToken.hpp"

class OperatorNode : public Node {
public:
    OperatorNode(char op_);

    OperatorNode(char op_, std::unique_ptr<Node> a_, std::unique_ptr<Node> b_);

    float calculate();

    void inOrderPrint(std::string &prefix, bool isLeft) const override;
private:
    char op;
    std::unique_ptr<Node> a;
    std::unique_ptr<Node> b;
};

#endif