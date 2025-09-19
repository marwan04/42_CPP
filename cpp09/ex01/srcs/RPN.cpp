#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) : _stack(other._stack) {}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        _stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {}

std::vector<std::string> RPN::tokenize(const std::string& expression) const {
    std::vector<std::string> tokens;
    std::istringstream iss(expression);
    std::string token;
    
    while (iss >> token) {
        tokens.push_back(token);
    }
    
    return tokens;
}

bool RPN::isOperator(const std::string& token) const {
    return token.length() == 1 && 
           (token[0] == '+' || token[0] == '-' || 
            token[0] == '*' || token[0] == '/');
}

bool RPN::isValidNumber(const std::string& token) const {
    if (token.empty())
        return false;
    
    // Handle negative numbers
    size_t start = 0;
    if (token[0] == '-' || token[0] == '+') {
        if (token.length() == 1)
            return false; // Just a sign is not a valid number
        start = 1;
    }
    
    // Check if all remaining characters are digits or decimal point
    bool hasDecimal = false;
    for (size_t i = start; i < token.length(); i++) {
        if (token[i] == '.') {
            if (hasDecimal)
                return false; // Multiple decimal points
            hasDecimal = true;
        } else if (!std::isdigit(token[i])) {
            return false;
        }
    }
    
    return true;
}

double RPN::performOperation(char op, double operand1, double operand2) const {
    switch (op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 == 0) {
                throw std::runtime_error("Division by zero");
            }
            return operand1 / operand2;
        default:
            throw std::runtime_error("Unknown operator");
    }
}

double RPN::evaluate(const std::string& expression) {
    // Clear the stack for fresh evaluation
    while (!_stack.empty()) {
        _stack.pop();
    }
    
    if (expression.empty()) {
        throw std::runtime_error("Empty expression");
    }
    
    // Check for invalid characters like parentheses
    if (expression.find('(') != std::string::npos || 
        expression.find(')') != std::string::npos) {
        throw std::runtime_error("Parentheses not supported");
    }
    
    std::vector<std::string> tokens = tokenize(expression);
    
    if (tokens.empty()) {
        throw std::runtime_error("No tokens found");
    }
    
    for (size_t i = 0; i < tokens.size(); i++) {
        const std::string& token = tokens[i];
        
        if (isValidNumber(token)) {
            // Convert string to double
            std::istringstream iss(token);
            double number;
            iss >> number;
            
            if (iss.fail()) {
                throw std::runtime_error("Invalid number format");
            }
            
            _stack.push(number);
        }
        else if (isOperator(token)) {
            if (_stack.size() < 2) {
                throw std::runtime_error("Insufficient operands for operator");
            }
            
            // Pop two operands (note the order: second popped is first operand)
            double operand2 = _stack.top();
            _stack.pop();
            double operand1 = _stack.top();
            _stack.pop();
            
            double result = performOperation(token[0], operand1, operand2);
            _stack.push(result);
        }
        else {
            throw std::runtime_error("Invalid token: " + token);
        }
    }
    
    // After processing all tokens, there should be exactly one result
    if (_stack.size() != 1) {
        if (_stack.empty()) {
            throw std::runtime_error("No result found");
        } else {
            throw std::runtime_error("Too many operands");
        }
    }
    
    return _stack.top();
}
