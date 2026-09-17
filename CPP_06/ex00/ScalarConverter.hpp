#pragma once

#include <string>
#include <iostream>
#include <exception>

enum LiteralType
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO,
    INVALID
};

class ScalarConverter
{
public:
    static void convert(const std::string& literal);

    class ConversionException : public std::exception
    {
    private:
        std::string msg;
    public:
        ConversionException(const std::string& msg);
        ~ConversionException() throw();
        const char* what() const throw();
    };

private:
    // not instantiable
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter& copy);
    ScalarConverter& operator=(const ScalarConverter& assn);

    static LiteralType detectType(const std::string& literal);

    static void handleChar(const std::string& literal);
    static void handleInt(const std::string& literal);
    static void handleFloat(const std::string& literal);
    static void handleDouble(const std::string& literal);
    static void handlePseudo(const std::string& literal, bool isFloatSuffix);

    static void printAll(double value, bool isPseudo, bool pseudoIsFloat);
};