#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <vector>

#include "Node.hpp"

class Calculator {
public:
    float calculate();
    
private:
    Node *binaryTree;

};

#endif