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

    // each takes the raw literal, parses it into its "native" type,
    // then hands off to printAll with the resulting double
    static void handleChar(const std::string& literal);
    static void handleInt(const std::string& literal);
    static void handleFloat(const std::string& literal);
    static void handleDouble(const std::string& literal);
    static void handlePseudo(const std::string& literal, bool isFloatSuffix);

    // shared printer: given the value as a double (plus flags for
    // "this came from a pseudo-literal" and which sub-kind), prints
    // char/int/float/double lines, throwing ConversionException
    // internally per-line where a cast is impossible
    static void printAll(double value, bool isPseudo, bool pseudoIsFloat);
};