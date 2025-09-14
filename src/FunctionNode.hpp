#ifndef FUNCTION_NODE_HPP
#define FUNCTION_NODE_HPP

#include <string>
#include <unordered_map>
#include <any>

#include "Node.hpp"

class FunctionNode : public Node {
public:
    float calculate() override;

    FunctionNode(std::string func, std::unique_ptr<Node> child);
    
    void inOrderPrint(std::string &prefix, bool isLeft) const override;
private:
    std::string func;
    std::unique_ptr<Node> child;
    std::unordered_map<std::string, std::any> mathFunctions;
};

#endif