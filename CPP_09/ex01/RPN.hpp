#pragma once

#include <stack>
#include <string>
#include <exception>
#include <sstream>
#include <cctype>
#include <climits>

class RPN
{
    private:
        std::stack<int> stack;
        RPN();
    
    public:
        RPN(std::string input);
        ~RPN();
        RPN(const RPN &copy);
        RPN& operator=(const RPN &assn);

        class BadInputException : public std::exception
        {
            private:
                std::string msg;
            public:
                BadInputException(const std::string& msg);
                ~BadInputException() throw();
                const char* what() const throw();
        };

        class OverflowException : public std::exception
        {
            private:
                std::string msg;
            public:
                OverflowException(const std::string& msg);
                ~OverflowException() throw();
                const char* what() const throw();
        };

        int getResult() const;

};