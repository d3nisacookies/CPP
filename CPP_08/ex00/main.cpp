#include "easyfind.hpp"
#include <vector>
#include <iostream>
#include <list>
#include <deque>


int main(void)
{
    const std::vector<int> v(3,42);
    std::vector<int> v2(3, 42);
    std::cout << "vector testing\n";
    std::cout << *easyfind(v, 42) << std::endl;
    try{std::cout << *easyfind(v2, 1) << std::endl;}
    catch (std::exception& e){ std::cout << e.what() << std::endl;}

    int arr[] = {3,42,44,45,1,2,23,32,100};
    std::list<int> l(arr, arr + sizeof(arr) / sizeof(arr[0]));
    const std::list<int> l2(arr, arr + sizeof(arr) / sizeof(arr[0]));
    std::cout << "list testing\n";
    std::cout << *easyfind(l2, 23) << std::endl;
    try {std::cout << *easyfind(l, 1000) << std::endl;}
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Deque testing\n";
    std::deque<int> d(arr, arr + sizeof(arr) / sizeof(arr[0]));
    std::cout << *easyfind(d, 42) << std::endl;
    const std::deque<int> d2(arr, arr + sizeof(arr) /  sizeof(arr[0]));
    try{std::cout << *easyfind(d2, 20000) << std::endl;}
    catch(std::exception& e){std::cout << e.what() << std::endl;}

    return 0;
}