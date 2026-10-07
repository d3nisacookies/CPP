#include "Span.hpp"

int main(void)
{
    Span sp(5);
    sp.addNumber(6); sp.addNumber(3); sp.addNumber(17);
    sp.addNumber(9); sp.addNumber(11);
    std::cout << sp.shortestSpan() << "\n";  // 2
    std::cout << sp.longestSpan()  << "\n";  // 14

    try { sp.addNumber(1); } catch (std::exception& e) { std::cout << e.what() << "\n"; }

    Span big(20000);
    std::vector<int> nums;
    for (int i = 0; i < 20000; ++i) nums.push_back(i * 3);
    big.addRange(nums.begin(), nums.end());
    std::cout << big.shortestSpan() << " " << big.longestSpan() << "\n";

}