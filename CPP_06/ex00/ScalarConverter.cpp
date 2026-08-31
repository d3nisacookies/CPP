#include "ScalarConverter.hpp"

static bool isPseudo(std::string s)
{
    if (s == "nan" || s == "+inf" || s == "-inf" || s == "nanf" ||
        s == "+inff" || s == "-inff")
        return true;
    return false;
}

static bool isFloat(std::string s)
{
    if (!s.empty() && s.back() == 'f')
        return true;
    return false;
}

static LiteralType CharOrInt(std::string& s)
{
    if (s[0] >= 48 && s[0] <= 57 )
        return LiteralType::INT;
    return LiteralType::CHAR;
}

LiteralType ScalarConverter::detectType(std::string& s)
{
    if (isPseudo(s))
        return LiteralType::PSEUDO;
    if (isFloat(s))
        return LiteralType::FLOAT;
    if (s.size() == 1)
        return(CharOrInt(s));

    return LiteralType::INVALID;
}