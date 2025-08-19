#ifndef FLOATNODE_HPP
#define FLOATNODE_HPP

#include "Node.hpp"

class FloatNode : public Node {
public:
    FloatNode(float val);

    float calculate();
    
private:
    float val;
};

#endif