#include "Array.hpp"
#include <algorithm>
#include <iostream>

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
Array<T>::Array(const Array<T>& a) : _data(new T[a._size]), _size(a._size)
{
    std::copy(a._data, a._data + _size, _data);
}
template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& a)
{
    if (this != &a)
    {
        delete [] _data;
        _data = new T[a._size];
        _size = a._size;
        std::copy(a._data, a._data + _size, _data);
    }
    return (*this);
}

template<typename T>
const T& Array<T>::operator[](int i)const
{
    if (i < 0 || i >= static_cast<int>(_size))
        throw OutOfBoundsException();
    return (_data[i]);
}

template<typename T>
T& Array<T>::operator[](int i)
{
    if (i < 0 || i >= static_cast<int>(_size))
        throw OutOfBoundsException();
    return (_data[i]);
}

template<typename T>
Array<T>::OutOfBoundsException::OutOfBoundsException()
{
    msg = "Index out of bounds";
}


template<typename T>
Array<T>::OutOfBoundsException::~OutOfBoundsException() throw() {}

template<typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
    return msg.c_str();
}

template<typename T>
unsigned int Array<T>::size() const
{
    return _size;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& a)
{
    for (unsigned int i = 0 ; i < a.size(); ++i)
    {
        os << i << ": " << a[i] << "\n";
    }
    return os;
}