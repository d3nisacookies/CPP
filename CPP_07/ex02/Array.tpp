#include "Array.hpp"
#include <algorithm>

template<typename T>
Array<T>::Array()
{
    _data = NULL;
    _size = 0;
}

template<typename T>
Array<T>::~Array()
{
    delete[] _data;
}

template<typename T>
Array<T>::Array(unsigned int n)
{
    _data = new T[n]();
    _size = n;
}

template<typename T>
Array<T>::Array(const Array<T>& a) : _size(a._size), _data(new T[a._size])
{
    std::copy(a._data, a._data + _size, _data);
}