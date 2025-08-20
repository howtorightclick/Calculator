#ifndef UNARYNODE_HPP
#define UNARYNODE_HPP

#include <string>

#include "Node.hpp"

class UnaryNode : public Node {
public:
    float calculate();

    UnaryNode(std::string func);
    
private:
    std::string func;
};

#endif