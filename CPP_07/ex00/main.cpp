#include <iostream>
#include <cstdlib>
#include "template.hpp"

// int isDigit(char *str)
// {
//     for (int i = 0; str[i] != '\0'; ++i)
//     {
//         if (str[i] < '0' || str[i] > '9')
//             return 0;
//     }
//     return 1;
// }

// int main(int ac, char **av)
// {
//     if (ac != 3 || !isDigit(av[1]) || !isDigit(av[2]))
//         return 0;
//     double a = std::atof(av[1]);
//     double b = std::atof(av[2]);
//     std::cout << "Testing Swap" << std::endl;
//     std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
//     swap(a,b);
//     std::cout << "After Swap: a = " << a << ", b = " << b << std::endl;

//     std::cout << "Testing Min" << std::endl;
//     std::cout << "a = " << a << ", b = " << b << std::endl;
//     const double &minRes = min(a,b);
//     std::cout << "Min :" << minRes << std::endl;

//     std::cout << "Testing Max" << std::endl;
//     std::cout << "a = " << a << ", b = " << b << std::endl;
//     const double &maxRes = max(a,b);
//     std::cout << "Max :" << maxRes << std::endl;

//     std::cout << "Testing for returning B when equal values." << std::endl;

//     std::cout << "Address of a: " << &a << std::endl;
//     std::cout << "Address of b: " << &b << std::endl;

//     if (&minRes == &b && &maxRes == &b) {
//         std::cout << "SUCCESS" << std::endl;
//     } else {
//         std::cout << "FAILURE" << std::endl;
//     }
//     return 0;

// }

// this is from the exercise
int main( void ) {
int a = 2;
int b = 3;
::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
std::string c = "chaine1";
std::string d = "chaine2";
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
return 0;
}