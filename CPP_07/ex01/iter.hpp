#pragma once
#include <iostream>

template<typename T, typename Functor>
void iter(T* arr, std::size_t length, Functor func)
{
    for (std::size_t i = 0; i < length; ++i)
    {
        func(arr[i]);
    }
}

template<typename T>
void print(const T& x)
{
    std::cout << x << ", ";
}

template<typename T>
void addThree( T& x)
{
    x += 3;
}
template<typename T>
void addS( T& x)
{
    x += 's';
}

template<typename T>
void printElement(const T& x)
{
    std::cout << x << std::endl;
}