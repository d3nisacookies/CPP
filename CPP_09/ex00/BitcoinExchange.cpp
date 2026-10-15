#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& file)
{
    if (file.length() < 4 || file.substr(file.length() - 4) != ".csv")
        throw FileException("File needs \".csv\" extenstion");
    
    std::ifstream ifs(file);
    if (!ifs.is_open())
        throw FileException("Could not open file");

    std::string line;
    std::getline(ifs , line);
    while (std::getline(ifs, line))
    {
        if (line.empty())
            continue;

        std::stringstream ss(line);
        std::string date;
        std::string rate_str;

        try
        {
            float rate = std::stof(rate_str);
            bc[date] = rate;
        }
        catch (const BadElementException& e)
        {
            std::cerr << "BadElementException: " << e.what() << std::endl;
        }
    }

}