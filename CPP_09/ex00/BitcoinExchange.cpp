#include "BitcoinExchange.hpp"


static bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 != 0;
}

static int daysInMonth(int year, int month)
{
    static const int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year))
        return 29;
    return days[month - 1];
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    for (std::string::size_type i = 0; i < date.length(); ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(static_cast<unsigned char>(date[i])))
            return false;
    }
    int year = (date[0] - '0') * 1000 + (date[1] - '0') * 100 + (date[2] - '0') * 10 +  (date[3] - '0');
    int month = (date[5] - '0') * 10 + (date[6] - '0');
    int day = (date[8] - '0') * 10 + (date[9] - '0');
    if (month < 1 || month > 12 || day < 1)
        return false;
    return day <= daysInMonth(year, month);
}

float BitcoinExchange::ParseRate(const std::string& str)
{
    if (str.empty())
        throw BadElementException("Empty Input");
    char* end;
    const char* start = str.c_str();
    errno = 0;
    double value = std::strtod(start, &end);
    if (end == start)
        throw BadElementException("Invalid rate");
    if (*end != '\0')
        throw BadElementException("Invalid rate");
    if (value != value || value > std::numeric_limits<double>::max() || value < -std::numeric_limits<double>::max())
        throw BadElementException("Rate must be finite");
    if (errno == ERANGE || value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max())
        throw BadElementException("Out of Range");

    return static_cast<float>(value);
}

BitcoinExchange::BitcoinExchange(const std::string& file)
{
    if (file.length() < 4 || file.substr(file.length() - 4) != ".csv")
        throw FileException("File needs \".csv\" extension");
    
    std::ifstream ifs(file.c_str());
    if (!ifs.is_open())
        throw FileException("Could not open file");

    std::string line;
    std::getline(ifs , line);
    while (std::getline(ifs, line))
    {
        if (!line.empty() && line[line.size() - 1] == '\r')
            line.erase(line.size() - 1);

        if (line.empty())
            continue;

        std::stringstream ss(line);
        std::string date;
        std::string rate_str;

        if (!std::getline(ss, date, ',') ||
            !std::getline(ss, rate_str))
        {
            std::cerr << "Invalid CSV line: " << line << std::endl;
            continue;
        }

        try
        {
            if (!isValidDate(date))
                throw BadElementException("Bad date :" + line);

            float rate = BitcoinExchange::ParseRate(rate_str);
            bc[date] = rate;
        }
        catch (const BadElementException& e)
        {
            std::cerr << "BadElementException: "
                      << e.what() << std::endl;
        }
    }
    if (bc.empty())
        throw FileException("No valid rows in DB.");
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& b) : bc(b.bc){}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& b)
{
    if (this != &b)
    {
        bc = b.bc;
    }
    return (*this);
}

float BitcoinExchange::getRate(const std::string& date) const
{
    std::map<std::string, float>::const_iterator it;
    it = this->bc.lower_bound(date);
    if (it != this->bc.end() && it->first == date)
    {
        return it->second;
    }
    if (it == bc.begin())
        throw BadElementException("no earlier date");
    --it;
    return it->second;
}

BitcoinExchange::BadElementException::BadElementException(const std::string& m)
    : msg(m) {}

BitcoinExchange::BadElementException::~BadElementException() throw() {}

const char* BitcoinExchange::BadElementException::what() const throw()
{
    return msg.c_str();
}

BitcoinExchange::FileException::FileException(const std::string& m)
    : msg(m) {}

BitcoinExchange::FileException::~FileException() throw() {}

const char* BitcoinExchange::FileException::what() const throw()
{
    return msg.c_str();
}