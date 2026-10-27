#include "RPN.hpp"


RPN::RPN(){}

RPN::~RPN(){}

RPN::RPN(const RPN &copy) : stack(copy.stack){}

RPN& RPN::operator=(const RPN &assn)
{
    if (this != &assn)
        stack = assn.stack;
    return *this;
}

RPN::RPN(std::string input)
{
    if (input.empty())
        throw BadInputException("Empty string");
    std::stringstream ss(input);
    std::string token;

    while (ss >> token)
    {
        if (token.size() == 1 && std::isdigit(token[0]))
            stack.push(token[0] - '0');
        else if (token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'))
        {
            char op = token[0];
            if (stack.size() < 2)
                throw BadInputException("Invalid Operations");
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();

            if (op == '+')
            {
                if ((b > 0 && a > INT_MAX - b) || (b < 0 && a < INT_MIN - b))
                    throw OverflowException("Overflow");
                stack.push(a + b);
            }
            else if (op == '-')
            {
                if ((b < 0 && a > INT_MAX + b) || (b > 0 && a < INT_MIN + b))
                    throw OverflowException("Overflow");
                stack.push(a - b);
            }
            else if (op == '*')
            {
                if (a > 0)
                {
                    if ((b > 0 && a > INT_MAX / b) || (b <= 0 && b < INT_MIN / a))
                        throw OverflowException("Overflow");
                }
                else if (a < 0)
                {
                    if ((b > 0 && a < INT_MIN / b) || (b <= 0 && b != 0 && b < INT_MAX / a))
                        throw OverflowException("Overflow");
                }
                stack.push(a * b);
            }
            else
            {
                if (b == 0)
                    throw BadInputException("Division by zero");
                if (a == INT_MIN && b == -1)
                    throw OverflowException("Overflow");
                stack.push(a / b);
            }
        }
        else
            throw BadInputException("Invalid token");
    }
    if (stack.size() != 1)
        throw BadInputException("Invalid expression");
}

int RPN::getResult() const
{
    return stack.top();
}

RPN::BadInputException::BadInputException(const std::string& msg) : msg(msg){}

RPN::BadInputException::~BadInputException() throw(){}

const char* RPN::BadInputException::what() const throw()
{
    return msg.c_str();
}

RPN::OverflowException::OverflowException(const std::string& msg) : msg(msg){}

RPN::OverflowException::~OverflowException() throw(){}

const char* RPN::OverflowException::what() const throw()
{
    return msg.c_str();
}