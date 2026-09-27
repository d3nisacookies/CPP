#pragma once

#include <ostream>
#include <istream>
#include <string>
#include <exception>

template<typename T>
class Array
{
    private:
        T* _data;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        ~Array();
        Array(const Array<T>& a);
        Array<T>& operator=(const Array<T>& a);
        T& operator[](int i);
        const T& operator[](int i) const;
        unsigned int size() const;
        class OutOfBoundsException : public std::exception
        {
            private:
                std::string msg;
            public:
                OutOfBoundsException();
                ~OutOfBoundsException() throw();
                const char* what() const throw();
        };

};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& a);

#include "Array.tpp"