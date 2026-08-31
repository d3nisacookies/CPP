#pragma once

#include <string>

enum LiteralType
{
    CHAR,
    INT,
    DOUBLE,
    FLOAT,
    PSEUDO,
    INVALID
};



class ScalarConverter
{
    private:

    public:
    LiteralType detectType(std::string& s);

    class InvalidValueException : public std::exception
    {
        private:
            std::string msg;
        public:
            InvalidValueException(const std::string msg);
            ~InvalidValueException() throw();
            const char* what() const throw();
    };
};