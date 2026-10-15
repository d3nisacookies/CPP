#include "BitcoinExchange.hpp"
#include <cctype>
#include <cerrno>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

static bool isNumberFormat(const std::string& s)
{
    std::string::size_type i = 0;
    bool digit = false;
    bool dot = false;

    if (!s.empty() && s[0] == '-')
        i = 1;
    for (; i < s.size(); ++i)
    {
        if (std::isdigit(static_cast<unsigned char>(s[i])))
            digit = true;
        else if (s[i] == '.' && !dot)
            dot = true;
        else
            return false;
    }
    return digit;
}

int main(int ac, char** av)
{
    if (ac != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    try
    {
        BitcoinExchange exchange("data.csv");

        std::ifstream infile(av[1]);
        if (!infile)
        {
            std::cerr << "Error: could not open file." << std::endl;
            return 1;
        }

        std::string line;
        bool firstLine = true;

        while (std::getline(infile, line))
        {
            if (!line.empty() && line[line.size() - 1] == '\r')
                line.erase(line.size() - 1);
            if (line.empty())
                continue;

            if (firstLine && line == "date | value")
            {
                firstLine = false;
                continue;
            }
            firstLine = false;

            try
            {
                std::string::size_type pos = line.find(" | ");
                if (pos == std::string::npos)
                    throw BitcoinExchange::BadElementException(
                        "bad input => " + line);

                std::string date = line.substr(0, pos);
                std::string valueStr = line.substr(pos + 3);

                if (!BitcoinExchange::isValidDate(date)
                    || !isNumberFormat(valueStr))
                    throw BitcoinExchange::BadElementException(
                        "bad input => " + line);

                if (valueStr[0] == '-')
                    throw BitcoinExchange::BadElementException(
                        "not a positive number.");

                double value = std::strtod(valueStr.c_str(), NULL);
                if (value > 1000)
                    throw BitcoinExchange::BadElementException(
                        "too large a number.");

                double rate = exchange.getRate(date);

                std::cout << date << " => " << value << " = "
                          << value * rate << std::endl;
            }
            catch (const BitcoinExchange::BadElementException& e)
            {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
    }
    catch (const BitcoinExchange::FileException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}