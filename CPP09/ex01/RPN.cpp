#include "RPN.hpp"
#include <stack>
#include <sstream>
#include <stdexcept>
#include <cctype>

RPN::RPN() {}
RPN::RPN(const RPN&) {}
RPN& RPN::operator=(const RPN&) { return *this; }
RPN::~RPN() {}

int RPN::evaluate(const std::string& expression) {
    std::stack<int> stack;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (token.size() == 1 && (token[0] == '+' || token[0] == '-' ||
                                   token[0] == '*' || token[0] == '/')) {
            if (stack.size() < 2)
                throw std::runtime_error("Error");

            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            int result;

            switch (token[0]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/':
                    if (b == 0)
                        throw std::runtime_error("Error");
                    result = a / b;
                    break;
                default:
                    throw std::runtime_error("Error");
            }
            stack.push(result);
        } else if (token.size() == 1 && std::isdigit(static_cast<unsigned char>(token[0]))) {
            stack.push(token[0] - '0');
        } else {
            throw std::runtime_error("Error");
        }
    }

    if (stack.size() != 1)
        throw std::runtime_error("Error");

    return stack.top();
}
