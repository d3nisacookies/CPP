#include "ScalarConverter.hpp"

#include <cstdlib>
#include <cmath>
#include <cctype>
#include <iomanip>
#include <limits>

namespace
{
    bool isIntegerString(const std::string& s)
    {
        if (s.empty())
            return false;
        std::size_t i = 0;
        if (s[0] == '+' || s[0] == '-')
            i = 1;
        if (i == s.size())
            return false;
        for (; i < s.size(); ++i)
        {
            if (!std::isdigit(static_cast<unsigned char>(s[i])))
                return false;
        }
        return true;
    }

    bool isDoubleString(const std::string& s)
    {
        if (s.empty())
            return false;
        char* end = 0;
        const double value = std::strtod(s.c_str(), &end);
        static_cast<void>(value);
        return (*end == '\0');
    }

    bool isFloatString(const std::string& s)
    {
        if (s.empty() || s[s.size() - 1] != 'f')
            return false;
        std::string tmp = s.substr(0, s.size() - 1);
        if (tmp.empty())
            return false;
        char* end = 0;
        const float value = std::strtof(tmp.c_str(), &end);
        static_cast<void>(value);
        return (*end == '\0');
    }

    bool isPseudo(const std::string& s)
    {
        return (s == "nan" || s == "nanf" || s == "+inf" || s == "+inff" ||
                s == "-inf" || s == "-inff" || s == "inf" || s == "inff");
    }

    bool isPrintableChar(char c)
    {
        return std::isprint(static_cast<unsigned char>(c)) != 0;
    }

    double parsePseudoValue(const std::string& literal)
    {
        if (literal == "nan" || literal == "nanf")
            return std::numeric_limits<double>::quiet_NaN();
        if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff")
            return std::numeric_limits<double>::infinity();
        if (literal == "-inf" || literal == "-inff")
            return -std::numeric_limits<double>::infinity();
        return 0.0;
    }
}

ScalarConverter::ConversionException::ConversionException(const std::string& msg)
    : msg(msg)
{
}

ScalarConverter::ConversionException::~ConversionException() throw()
{
}

const char* ScalarConverter::ConversionException::what() const throw()
{
    return msg.c_str();
}

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter&) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&)
{
    return *this;
}

LiteralType ScalarConverter::detectType(const std::string& literal)
{
    if (isPseudo(literal))
        return PSEUDO;
    if (isFloatString(literal))
        return FLOAT;
    if (literal.size() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0])))
        return CHAR;
    if (isIntegerString(literal))
        return INT;
    if (isDoubleString(literal))
        return DOUBLE;
    return INVALID;
}

void ScalarConverter::handleChar(const std::string& literal)
{
    printAll(static_cast<double>(literal[0]), false, false);
}

#include <cerrno>   // for errno, ERANGE

void ScalarConverter::handleInt(const std::string& literal)
{
    errno = 0;                    // reset BEFORE the call
    char* end = 0;
    const long value = std::strtol(literal.c_str(), &end, 10);

    // now check immediately after, before anything else touches errno
    if (*end != '\0' || errno == ERANGE ||
        value < std::numeric_limits<int>::min() ||
        value > std::numeric_limits<int>::max())
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    printAll(static_cast<double>(value), false, false);
}

void ScalarConverter::handleFloat(const std::string& literal)
{
    char* end = 0;
    const float value = std::strtof(literal.c_str(), &end);
    if (*end != '\0')
        throw ConversionException("float: impossible");
    printAll(static_cast<double>(value), false, false);
}

void ScalarConverter::handleDouble(const std::string& literal)
{
    char* end = 0;
    const double value = std::strtod(literal.c_str(), &end);
    if (*end != '\0')
        throw ConversionException("double: impossible");
    printAll(value, false, false);
}

void ScalarConverter::handlePseudo(const std::string& literal, bool isFloatSuffix)
{
    (void)isFloatSuffix;
    printAll(parsePseudoValue(literal), true, isFloatSuffix);
}

void ScalarConverter::printAll(double value, bool isPseudo, bool pseudoIsFloat)
{
    static_cast<void>(pseudoIsFloat);
    try
    {
        std::cout << "char: ";
        if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
            throw ConversionException("impossible");
        const char c = static_cast<char>(value);
        if (!isPrintableChar(c))
            throw ConversionException("Non displayable");
        std::cout << "'" << c << "'" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "int: ";
        if (std::isnan(value) || std::isinf(value) || value < static_cast<double>(std::numeric_limits<int>::min()) ||
            value > static_cast<double>(std::numeric_limits<int>::max()))
            throw ConversionException("impossible");
        std::cout << static_cast<int>(value) << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "float: ";
        if (isPseudo && std::isnan(value))
            std::cout << "nanf" << std::endl;
        else if (isPseudo && value == std::numeric_limits<double>::infinity())
            std::cout << "+inff" << std::endl;
        else if (isPseudo && value == -std::numeric_limits<double>::infinity())
            std::cout << "-inff" << std::endl;
        else
        {
            const float f = static_cast<float>(value);
            std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
        }
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "double: ";
        if (isPseudo && std::isnan(value))
            std::cout << "nan" << std::endl;
        else if (isPseudo && value == std::numeric_limits<double>::infinity())
            std::cout << "+inf" << std::endl;
        else if (isPseudo && value == -std::numeric_limits<double>::infinity())
            std::cout << "-inf" << std::endl;
        else
        {
            std::cout << std::fixed << std::setprecision(1) << value << std::endl;
        }
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void ScalarConverter::convert(const std::string& literal)
{
    const LiteralType type = detectType(literal);

    if (type == INVALID)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    try
    {
        switch (type)
        {
            case CHAR:
                handleChar(literal);
                break;
            case INT:
                handleInt(literal);
                break;
            case FLOAT:
                handleFloat(literal);
                break;
            case DOUBLE:
                handleDouble(literal);
                break;
            case PSEUDO:
                handlePseudo(literal, literal.find("f") != std::string::npos);
                break;
            default:
                throw ConversionException("invalid literal");
        }
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

