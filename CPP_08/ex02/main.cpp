#include "MutantStack.hpp"
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <numeric>
#include <iterator>

// static void check(const char* label, bool ok)
// {
//     std::cout << (ok ? "[OK] " : "[KO] ") << label << std::endl;
// }

static void subjectTest()
{
    std::cout << "--- subject test ---" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
}

static void listTest()
{
    std::cout << "--- subject test (std::list) ---" << std::endl;
    std::list<int> mstack;
    mstack.push_back(5);
    mstack.push_back(17);
    std::cout << mstack.back() << std::endl;
    mstack.pop_back();
    std::cout << mstack.size() << std::endl;
    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    mstack.push_back(0);
    std::list<int>::iterator it = mstack.begin();
    std::list<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::list<int> s(mstack);
}

// static void emptyAndSingle()
// {
//     std::cout << "--- empty / single ---" << std::endl;
//     MutantStack<int> e;
//     check("empty: begin == end", e.begin() == e.end());
//     check("empty: rbegin == rend", e.rbegin() == e.rend());
//     check("empty: empty() and size() == 0", e.empty() && e.size() == 0);

//     MutantStack<int> one;
//     one.push(42);
//     check("single: begin != end", one.begin() != one.end());
//     check("single: *begin == 42", *one.begin() == 42);
//     MutantStack<int>::iterator it = one.begin();
//     ++it;
//     check("single: ++begin == end", it == one.end());
//     check("single: *rbegin == 42", *one.rbegin() == 42);
// }

// static void orderTests()
// {
//     std::cout << "--- order / tracking ---" << std::endl;
//     MutantStack<int> m;
//     for (int i = 1; i <= 5; ++i)
//         m.push(i * 10);

//     std::cout << "forward: ";
//     for (MutantStack<int>::iterator it = m.begin(); it != m.end(); ++it)
//         std::cout << *it << " ";
//     std::cout << std::endl;

//     std::cout << "reverse: ";
//     for (MutantStack<int>::reverse_iterator it = m.rbegin(); it != m.rend(); ++it)
//         std::cout << *it << " ";
//     std::cout << std::endl;

//     check("last element == top()", *(m.end() - 1) == m.top());

//     m.pop();
//     check("after pop: size 4, top 40", m.size() == 4 && m.top() == 40);
//     m.push(99);
//     check("after push: top 99, last == 99", m.top() == 99 && *(m.end() - 1) == 99);

//     for (MutantStack<int>::iterator it = m.begin(); it != m.end(); ++it)
//         *it *= 2;
//     check("write through iterator: top doubled", m.top() == 198);
// }

// static void constTests()
// {
//     std::cout << "--- const ---" << std::endl;
//     MutantStack<int> m;
//     for (int i = 1; i <= 4; ++i)
//         m.push(i);
//     const MutantStack<int> cm(m);

//     std::cout << "const forward: ";
//     for (MutantStack<int>::const_iterator it = cm.begin(); it != cm.end(); ++it)
//         std::cout << *it << " ";
//     std::cout << std::endl;

//     std::cout << "const reverse: ";
//     for (MutantStack<int>::const_reverse_iterator it = cm.rbegin(); it != cm.rend(); ++it)
//         std::cout << *it << " ";
//     std::cout << std::endl;

//     check("const: size 4", cm.size() == 4);
//     // MutantStack<int>::const_iterator ci = cm.begin();
//     // *ci = 5;   // must NOT compile
// }

// static void copyTests()
// {
//     std::cout << "--- copy / assign ---" << std::endl;
//     MutantStack<int> a;
//     a.push(1);
//     a.push(2);
//     MutantStack<int> b(a);
//     MutantStack<int> c;
//     c.push(100);
//     c = a;
//     a.push(3);
//     check("copy ctor independent", b.size() == 2 && a.size() == 3);
//     check("assignment independent", c.size() == 2 && c.top() == 2);
//     MutantStack<int>& ref = c;
//     c = ref;
//     check("self-assignment safe", c.size() == 2 && c.top() == 2);
//     check("self-assignment safe", c.size() == 2 && c.top() == 2);

//     std::stack<int> s(a);
//     s.push(7);
//     check("std::stack conversion is a copy", s.size() == a.size() + 1);
// }

// static void typeTests()
// {
//     std::cout << "--- other types ---" << std::endl;
//     MutantStack<std::string> ms;
//     ms.push("a");
//     ms.push("b");
//     ms.push("c");
//     std::cout << "strings: ";
//     for (MutantStack<std::string>::iterator it = ms.begin(); it != ms.end(); ++it)
//         std::cout << *it << " ";
//     std::cout << std::endl;

//     MutantStack<double> md;
//     md.push(1.5);
//     md.push(2.5);
//     std::cout << "doubles: ";
//     for (MutantStack<double>::iterator it = md.begin(); it != md.end(); ++it)
//         std::cout << *it << " ";
//     std::cout << std::endl;
// }

// static void bigAndAlgoTests()
// {
//     std::cout << "--- big / algorithms ---" << std::endl;
//     MutantStack<int> big;
//     for (int i = 0; i < 10000; ++i)
//         big.push(i);
//     check("distance == 10000", std::distance(big.begin(), big.end()) == 10000);
//     check("sum == 49995000", std::accumulate(big.begin(), big.end(), 0) == 49995000);
//     check("find 9999", std::find(big.begin(), big.end(), 9999) != big.end());
//     check("find 10000 fails", std::find(big.begin(), big.end(), 10000) == big.end());

//     MutantStack<int> m;
//     m.push(5); m.push(3); m.push(5); m.push(8);
//     check("count of 5 == 2", std::count(m.begin(), m.end(), 5) == 2);
//     std::reverse(m.begin(), m.end());
//     check("after reverse: top == 5, first == 8", m.top() == 5 && *m.begin() == 8);
// }

int main()
{
    subjectTest();
    listTest();
    // emptyAndSingle();
    // orderTests();
    // constTests();
    // copyTests();
    // typeTests();
    // bigAndAlgoTests();
    return 0;
}