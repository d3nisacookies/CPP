#pragma once


#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <exception>
#include <fstream>
#include <cstdlib>
#include <cerrno>
#include <cmath>
#include <limits>

class BitcoinExchange
{
    private:
    std::map<std::string , float> bc;
    BitcoinExchange();

    public:
    explicit BitcoinExchange(const std::string& file);
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& b);
    BitcoinExchange& operator=(const BitcoinExchange& b);
    
    float getRate(const std::string& date) const;
    float ParseRate(const std::string& str);
    static bool isValidDate(const std::string& date);

    class FileException : public std::exception
    {
        private:
            std::string msg;
        public:
            FileException(const std::string& msg);
            ~FileException() throw();
            const char* what() const throw();
    };
    
    class BadElementException : public std::exception
    {
        private:
            std::string msg;
        public:
            BadElementException(const std::string& msg);
            ~BadElementException() throw();
            const char* what() const throw();
    };
};