#include <iostream>

#include "FunctionNode.hpp"

FunctionNode::FunctionNode(std::string func, std::unique_ptr<Node> child):
    func    (func)
{
    child = std::move(child);
}

float FunctionNode::calculate() {

    

    return 0;
}

void FunctionNode::inOrderPrint(std::string &prefix, bool isLeft) const {
    std::cout << prefix;
    std::cout << (isLeft ? "├──" : "└──");
    std::cout << func << std::endl;

    std::string newPrefix = prefix + (isLeft ? "│   " : "    ");
    child->inOrderPrint(newPrefix, true);
}