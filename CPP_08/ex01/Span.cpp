#include "Span.hpp"
#include <algorithm>
#include <climits>


Span::Span() : _v() , _max(0) {}

Span::~Span(){}

Span::Span(unsigned int N) : _v() , _max(N) 
{
    _v.reserve(N);
}

Span::Span(const Span& s) : _v(s._v), _max(s._max) {}

Span& Span::operator=(const Span& s)
{
    if (this != &s)
    {
        this->_max = s._max;
        this->_v = s._v;
    }
    return *this;
}

void Span::addNumber(int i)
{
    if (_v.size() == _max)
    {
        throw MaxLimitException();
    }
   _v.push_back(i);
}

unsigned int Span::longestSpan() const
{
    if (_v.size() <= 2 )
        throw NotEnoughElementsException();
    int lo = *std::min_element(_v.begin(), _v.end());
    int hi = *std::max_element(_v.begin(), _v.end());
    return (static_cast<unsigned int>(hi) - static_cast<unsigned int>(lo));
}

unsigned int Span::shortestSpan() const
{
    if (_v.size() <= 2)
        throw NotEnoughElementsException();
    
    std::vector<int> sorted(_v);
    std::sort(sorted.begin(), sorted.end());

    unsigned int best = UINT_MAX;
    for (size_t i = 1; i < sorted.size(); ++i)
    {
        unsigned int diff = static_cast<unsigned int>(sorted[i]) - static_cast<unsigned int>(sorted[i - 1]);
        if (diff > best)
            best = diff;
    }
    return best;
}

const char* Span::MaxLimitException::what() const throw()
{
    return "Max Limit reached";    
}

const char* Span::NotEnoughElementsException::what() const throw()
{
    return "Not enough Elements in the array";
}