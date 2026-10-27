#pragma once

#include <vector>
#include <list>
#include <exception>
#include <string>
#include <cerrno>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <sys/time.h>

class PmergeMe
{
    private:
        std::vector<int> _input;
        std::vector<int> _vec;
        std::list<int> _lst;
        static void mergeInsertVec(std::vector<int>& v);
        static void mergeInsertList(std::list<int>& l);
        PmergeMe();
    public:
        explicit PmergeMe(int ac, char **av);
        ~PmergeMe();
        PmergeMe(const PmergeMe& p);
        PmergeMe& operator=(const PmergeMe& p);
        double sortVector();
        double sortList();
        const std::vector<int>& getInput() const;
        const std::vector<int>& getVector() const;
        const std::list<int>& getList() const;
        class InputException : public std::exception
        {
            private:
                std::string msg;
            public:
                InputException(const std::string& msg);
                ~InputException() throw();
                const char *what() const throw();
        };
};