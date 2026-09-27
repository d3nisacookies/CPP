#include "Array.hpp"
#include <iostream>
#include <string>

int main(void)
{
    
    std::cout << "  Default constructor  " << std::endl;
    Array<int> empty;
    std::cout << "size: " << empty.size() << std::endl;

    std::cout << "\n  Sized constructor (zero-init check)  " << std::endl;
    Array<int> nums(5);
    std::cout << nums << std::endl;

    std::cout << "\n  Mutating via operator[]  " << std::endl;
    for (unsigned int i = 0; i < nums.size(); ++i)
        nums[i] = i * 10;
    std::cout << nums << std::endl;

    std::cout << "\n  Copy constructor (deep copy check)  " << std::endl;
    Array<int> copy(nums);
    copy[0] = 999;
    std::cout << "original: " << nums << std::endl;
    std::cout << "copy:     " << copy << std::endl;

    std::cout << "\n  operator= (deep copy + self-assignment)  " << std::endl;
    Array<int> assigned;
    assigned = nums;
    assigned[1] = 777;
    std::cout << "nums:     " << nums << std::endl;
    std::cout << "assigned: " << assigned << std::endl;
    assigned = assigned;
    std::cout << "after self-assign: " << assigned << std::endl;

    std::cout << "\n  const correctness  " << std::endl;
    const Array<int> constNums(nums);
    std::cout << "const element read: " << constNums[0] << std::endl;

    std::cout << "\n  Out-of-bounds exception  " << std::endl;
    try
    {
        std::cout << nums[100] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try
    {
        std::cout << nums[-1] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n  Different type (std::string)  " << std::endl;
    Array<std::string> words(3);
    words[0] = "hello";
    words[1] = "world";
    words[2] = "!";
    std::cout << words << std::endl;

     std::cout << "\n  Edge case: zero-sized array  " << std::endl;
    Array<int> zero(0);
    std::cout << "zero size: " << zero.size() << std::endl;
    try
    {
        std::cout << zero[0] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n  Edge case: operator= with different sizes  " << std::endl;
    Array<int> big(10);
    for (unsigned int i = 0; i < big.size(); ++i)
        big[i] = i;
    assigned = big;
    std::cout << "assigned after growing: " << assigned << std::endl;
    std::cout << "assigned size: " << assigned.size() << std::endl;

    std::cout << "\n  Edge case: chained assignment  " << std::endl;
    Array<int> chainA(3);
    Array<int> chainB(3);
    Array<int> chainC(3);
    for (unsigned int i = 0; i < 3; ++i)
        chainC[i] = i + 100;
    chainA = chainB = chainC;
    std::cout << "chainA: " << chainA << std::endl;
    std::cout << "chainB: " << chainB << std::endl;

    std::cout << "\n  Edge case: chained operator<<  " << std::endl;
    std::cout << chainA << " and " << chainB << std::endl;

    std::cout << "\n  Edge case: copy constructor from empty array  " << std::endl;
    Array<int> emptySrc;
    Array<int> emptyCopy(emptySrc);
    std::cout << "emptyCopy size: " << emptyCopy.size() << std::endl;


    return 0;
}