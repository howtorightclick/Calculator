#include "FloatNode.hpp"

FloatNode::FloatNode(float val) {
    FloatNode::val = val;
}

float FloatNode::calculate() {
    return val; 
}