#include "iter.hpp"

int main(void)
{
    std::size_t num[] = {1,2,3,4,5,6,7,8,9,10};
    const std::size_t len = 10;

    std::cout << "Before :" << std::endl;
    iter(num, len, print<std::size_t>);
    std::cout << std::endl;
    iter(num, len, addThree<std::size_t>);

    std::cout << "After adding 3 to all" << std::endl;
    iter(num, len, print<std::size_t>);
    std::cout << std::endl;

    std::string words[] = {"cat", "dog", "banana"};
    std::cout << "Before :" << std::endl;
    iter(words, 3, print<std::string>);
    std::cout << std::endl;
    iter(words, 3, addS<std::string>);
    std::cout << "After adding 's' to all" << std::endl;
    iter(words, 3, print<std::string>);
    std::cout << std::endl;
    return 0;
}