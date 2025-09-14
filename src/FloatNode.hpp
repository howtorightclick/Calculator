#ifndef FLOATNODE_HPP
#define FLOATNODE_HPP

#include "Node.hpp"

class FloatNode : public Node {
public:
    FloatNode(float val);

    float calculate() override;

    void inOrderPrint(std::string &prefix, bool isLeft) const override;
    
private:
    float val;
};

#endif