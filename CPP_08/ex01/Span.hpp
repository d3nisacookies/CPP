#pragma once
#include <exception>
#include <algorithm>
#include <iostream>
#include <vector>


class Span
{
    private:
        std::vector<int> _v;
        unsigned int _max;

    public:
        Span();
        ~Span();
        Span(unsigned int N);
        Span(const Span& s);
        Span& operator=(const Span& s);
        void addNumber(int i);
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;
        template <typename It>
        void addRange(It begin, It end);
        class MaxLimitException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class NotEnoughElementsException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

};

#include "Span.tpp"


