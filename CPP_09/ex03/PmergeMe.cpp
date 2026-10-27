#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(int ac, char** av)
{
    if (ac < 2)
        throw InputException("No input");
    for (int i = 1; i < ac; ++i)
    {
        std::string s = av[i];
        if (s.empty())
            throw InputException("Empty input");
        for (std::string::size_type j = 0; j < s.length(); ++j)
        {
            if (!std::isdigit(static_cast<unsigned char>(s[j])))
                throw InputException("Bad input");
        }
        errno = 0;
        long n = std::strtol(s.c_str(), NULL, 10);
        if (errno == ERANGE || n > INT_MAX || n == 0)
            throw InputException("Bad input");
        int v = static_cast<int>(n);
        if (std::find(_input.begin(), _input.end(), v) != _input.end())
            throw InputException("Duplicate");
        _input.push_back(v);
    }   
}

PmergeMe::PmergeMe(const PmergeMe& p) : _input(p._input) , _vec(p._vec), _lst(p._lst) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& p)
{
    if (this != &p)
    {
        _input = p._input;
        _vec = p._vec;
        _lst = p._lst;
    }
    return *this;
}

const std::vector<int>& PmergeMe::getVector() const
{
    return _vec;
}

const std::list<int>& PmergeMe::getList() const
{
    return _lst;
}

PmergeMe::InputException::InputException(const std::string& msg){ this->msg = msg;}

PmergeMe::InputException::~InputException() throw() {}

const char* PmergeMe::InputException::what() const throw()
{
    return (msg.c_str());
}

static double getTime()
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    return(tv.tv_sec * 1000000.0) + tv.tv_usec;
}

double PmergeMe::sortVector()
{
    double start;
    double end;

    start = getTime();
    _vec.assign(_input.begin(), _input.end());
    mergeInsertVec(_vec);
    end = getTime();
    return (end - start);
}

double PmergeMe::sortList()
{
    double start;
    double end;

    start =  getTime();
    _lst.assign(_input.begin(), _input.end());
    mergeInsertList(_lst);
    end = getTime();
    return (end - start);
}

static std::vector<size_t> getOrder(size_t count)
{
    std::vector<size_t> order;
    size_t previous = 1;
    size_t current = 3;

    while (previous < count)
    {
        size_t end = std::min(current, count);
        size_t i = end;

        while ( i > previous)
            order.push_back(i--);
        size_t next = current + 2 * previous;
        previous = current;
        current = next;
    }
    return order;
}

static std::list<size_t> getOrderList(size_t count)
{
    std::list<size_t> order;
    size_t previous = 1;
    size_t current = 3;

    while (previous < count)
    {
        size_t end = std::min(current, count);
        size_t i = end;
        while (i > previous)
            order.push_back(i--);
        size_t next = current + 2 * previous;
        previous = current;
        current = next;
    }
    return order;
}

void PmergeMe::mergeInsertVec(std::vector<int>& v)
{
    size_t n = v.size();
    if (n < 2)
        return;

    bool hasStraggler = (n % 2 != 0);
    int straggler = 0;
    if (hasStraggler)
        straggler = v[n - 1];

    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i + 1 < n; i += 2)
    {
        int big = std::max(v[i], v[i + 1]);
        int small = std::min(v[i], v[i + 1]);
        pairs.push_back(std::make_pair(big, small));
    }

    std::vector<int> bigs;
    for (size_t i = 0; i < pairs.size(); ++i)
        bigs.push_back(pairs[i].first);
    mergeInsertVec(bigs);

    std::vector<int> chain;
    std::vector<int> pend;
    for (size_t i = 0; i < bigs.size(); ++i)
    {
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (pairs[j].first == bigs[i])
            {
                chain.push_back(bigs[i]);
                pend.push_back(pairs[j].second);
                break;
            }
        }
    }

    chain.insert(chain.begin(), pend[0]);

    std::vector<size_t> order = getOrder(pend.size());
    for (size_t i = 0; i < order.size(); ++i)
    {
        size_t k = order[i];
        int b = pend[k - 1];
        int a = bigs[k - 1];
        std::vector<int>::iterator upper = std::find(chain.begin(), chain.end(), a);
        std::vector<int>::iterator pos = std::lower_bound(chain.begin(), upper, b);
        chain.insert(pos, b);
    }

    if (hasStraggler)
    {
        std::vector<int>::iterator pos = std::lower_bound(chain.begin(), chain.end(), straggler);
        chain.insert(pos, straggler);
    }
    v = chain;
}

static int nth(const std::list<int>& l, size_t k)
{
    std::list<int>::const_iterator it = l.begin();
    std::advance(it, k);
    return *it;
}

void PmergeMe::mergeInsertList(std::list<int>& l)
{
    size_t n = l.size();
    if (n < 2)
        return;
    bool hasStraggler = (n % 2 != 0);
    int straggler = 0;
    if (hasStraggler)
        straggler = nth(l, n - 1);

    std::list<std::pair<int, int> > pairs;
    std::list<int>::iterator it = l.begin();
    for (size_t i = 0; i + 1 < n; i +=2 )
    {
        int x = *it;
        ++it;
        int y = *it;
        ++it;
        pairs.push_back(std::make_pair(std::max(x,y) , std::min(x,y)));
    }
    std::list<int> bigs;
    std::list<std::pair<int, int> >::iterator pit;
    for(pit = pairs.begin(); pit != pairs.end(); ++pit)
    {
        bigs.push_back(pit->first);
    }
    mergeInsertList(bigs);

    std::list<int> chain;
    std::list<int> pend;
    for (it = bigs.begin(); it != bigs.end(); ++it)
    {
        for (pit = pairs.begin(); pit != pairs.end(); ++pit)
        {
            if (pit->first == *it)
            {
                chain.push_back(*it);
                pend.push_back(pit->second);
                break;
            }
        }
    }
    chain.push_front(pend.front());
    std::list<size_t> order = getOrderList(pend.size());
    std::list<size_t>::iterator oit;
    for (oit = order.begin(); oit != order.end(); ++oit)
    {
        size_t k = *oit;
        int b = nth(pend, k - 1);
        int a= nth(bigs, k - 1);
        std::list<int>::iterator upper = std::find(chain.begin(), chain.end(), a);
        std::list<int>::iterator pos = std::lower_bound(chain.begin(), upper, b);
        chain.insert(pos, b);
    }
    if (hasStraggler)
    {
        std::list<int>::iterator pos = std::lower_bound(chain.begin(), chain.end(), straggler);
        chain.insert(pos, straggler);
    }
    l = chain;
}

const std::vector<int>& PmergeMe::getInput() const
{
    return _input;
}