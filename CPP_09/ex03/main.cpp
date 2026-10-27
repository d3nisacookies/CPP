#include "PmergeMe.hpp"
#include <iostream>
#include <iomanip>

template <typename C>
static void printContainer(const std::string& label, const C& c)
{
    std::cout << label;
    for (typename C::const_iterator it = c.begin(); it != c.end(); ++it)
        std::cout << " " << *it;
    std::cout << std::endl;
}

int main(int ac, char **av)
{
    try
    {
        PmergeMe pm(ac, av);

        printContainer("Before:", pm.getInput());
        double tVec = pm.sortVector();
        double tLst = pm.sortList();
        printContainer("After: ", pm.getVector());

        std::cout << std::fixed << std::setprecision(5);
        std::cout << "Time to process a range of " << pm.getInput().size()
                  << " elements with std::vector : " << tVec << " us" << std::endl;
        std::cout << "Time to process a range of " << pm.getInput().size()
                  << " elements with std::list   : " << tLst << " us" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}