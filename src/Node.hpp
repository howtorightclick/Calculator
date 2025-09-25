#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include <memory>

// Template specialization to handle different types.
class Node {
public:
    virtual float calculate() = 0;    

    virtual void insert(std::unique_ptr<Node> child) {
        children.insert(children.begin(), std::move(child));
    };

    virtual void inOrderPrint(std::string &prefix, bool isLeft) const = 0;
private:
    std::vector<std::unique_ptr<Node>> children;
};

#endif