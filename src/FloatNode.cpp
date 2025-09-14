#include <iostream>

#include "FloatNode.hpp"

FloatNode::FloatNode(float val) {
    FloatNode::val = val;
}

float FloatNode::calculate() {
    return val; 
}

void FloatNode::inOrderPrint(std::string &prefix, bool isLeft) const {
    std::cout << prefix;
    std::cout << (isLeft ? "├──" : "└──");
    //std::cout << val << std::endl;
}