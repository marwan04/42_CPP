#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <cctype>

class RPN {
private:
    std::stack<double> _stack;
    
    bool isOperator(const std::string& token) const;
    bool isValidNumber(const std::string& token) const;
    double performOperation(char op, double operand1, double operand2) const;
    std::vector<std::string> tokenize(const std::string& expression) const;

public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();
    
    double evaluate(const std::string& expression);
};

#endif