#ifndef OPERAND_NODE_HPP
#define OPERAND_NODE_HPP

template<class T>
class OperandNode
{
private:
    T operand;
    /* data */
public:
    OperandNode(T arg);
    ~OperandNode();

    T calculate() override;
};

#endif