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
        unsigned int size;
    public:
        Array();
        Array(unsigned int n);
        ~Array();
        Array(const Array& a);
        Array& operator=(const Array<T>& a);
        T& operator[](int i);
        const T& operator[](int i) const ;
        class OutOfBoundsException : public std::exception
        {
            private:
                std::string msg;
            public:
                OutOfBoundsException();
                ~OutOfBoundsException();
                const char* what() const throw();
        };

};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& a);

template<typename T>
std::ostream& operator<<(std::ostream& os, Array<T>& a);