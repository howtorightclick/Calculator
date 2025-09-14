#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include <string>
#include <vector>
#include <any>

class Function {
/**
 * A function that can be executed given the correct arguments.
 * The return type should be validated.
 * 
 * 
 * 
 */
public:
    
    std::string getReturnType();
    
    int getNumArgs();

    std::vector<std::string> getArgTypes();

    virtual std::any execute(std::vector<std::any> &args) = 0;

private:
    // Each arg needs to know its type and value

    int numArgs;
    std::string name;
    std::vector<std::string> argTypes;
    std::string returnType;
};

#endif