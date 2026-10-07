#include "Span.hpp"

template <typename It>
void Span::addRange(It begin, It end)
{
    if (_v.size() + std::distance(begin, end) > _max)
        throw MaxLimitException();
    _v.insert(_v.end(), begin, end);
}
