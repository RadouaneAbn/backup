#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other) : _vec(other._vec), _deq(other._deq)
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _vec = other._vec;
        _deq = other._deq;
    }
    return *this;
}

std::vector<int> PmergeMe::generateJacobsthalSequenceVec(int n)
{
    std::vector<int> sequence;
    if (n <= 0)
        return sequence;

    sequence.push_back(0);
    if (n == 1)
        return sequence;

    sequence.push_back(1);
    for (int i = 2; i < n; ++i)
    {
        int next = sequence[i - 1] + 2 * sequence[i - 2];
        sequence.push_back(next);
    }
    return sequence;
}

std::deque<int> PmergeMe::generateJacobsthalSequenceDeq(int n)
{
    std::deque<int> sequence;
    if (n <= 0)
        return sequence;

    sequence.push_back(0);
    if (n == 1)
        return sequence;

    sequence.push_back(1);
    for (int i = 2; i < n; ++i)
    {
        int next = sequence[i - 1] + 2 * sequence[i - 2];
        sequence.push_back(next);
    }
    return sequence;
}

void PmergeMe::parseInput(int argc, char **argv)
{
    int int_value;
    for (int i = 1; i < argc; ++i)
    {
        std::string       arg = argv[i];
        std::stringstream ss(arg);
        std::string       token;

        while (ss >> token)
        {
            for (size_t j = 0; j < token.length(); ++j)
            {
                if (!std::isdigit(token[j]) && !(j == 0 && token[j] == '+'))
                    throw std::runtime_error("Error: only integer values are allowed.");
            }

            long value = std::atol(token.c_str());
            if (value < 0)
                throw std::runtime_error("Error: only positive integers are allowed.");
            if (value > std::numeric_limits<int>::max())
                throw std::runtime_error("Error: integer value out of range.");

            int_value = static_cast<int>(value);

            std::vector<int>::iterator it_vec = _vec.begin();
            if (std::find(it_vec, _vec.end(), int_value) != _vec.end())
                throw std::runtime_error("Error: duplicate values are not allowed.");
            std::deque<int>::iterator it_deq = _deq.begin();
            if (std::find(it_deq, _deq.end(), int_value) != _deq.end())
                throw std::runtime_error("Error: duplicate values are not allowed.");

            _vec.push_back(int_value);
            _deq.push_back(int_value);
        }
    }
    if (_vec.empty() || _deq.empty())
        throw std::runtime_error("Error: no elements provided.");
}

void PmergeMe::sortVector(std::vector<int> &vec)
{
    if (vec.size() <= 1)
        return;

    bool hasLeftover = vec.size() % 2 != 0;
    int  leftOver    = 0;
    if (hasLeftover)
    {
        leftOver = vec.back();
        vec.pop_back();
    }

    // 1 - pair and determine larger and smaller elements
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < vec.size(); i += 2)
    {
        if (vec[i] < vec[i + 1])
            pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
        else
            pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
    }

    // 2 - sort main chain recursively
    std::vector<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i)
        mainChain.push_back(pairs[i].second);
    sortVector(mainChain);

    // 3 - re align pending elements with sorted main chain
    std::vector<int> pending;
    std::vector<int> partners;
    for (size_t i = 0; i < mainChain.size(); ++i)
    {
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (mainChain[i] == pairs[j].second)
            {
                pending.push_back(pairs[j].first);
                partners.push_back(pairs[j].second);
                break;
            }
        }
    }
    // 4 - Insert first pending item
    mainChain.insert(mainChain.begin(), pending[0]);

    // 5 - Insert remaining pending elements using jacobstal sequence
    std::vector<int>  jacobsthalSeq = generateJacobsthalSequenceVec(pending.size());
    std::vector<bool> inserted(pending.size(), false);
    inserted[0] = true;

    for (size_t i = 1; i < jacobsthalSeq.size(); ++i)
    {
        size_t index = jacobsthalSeq[i];
        if (index >= pending.size())
            index = pending.size() - 1;
        while (index > 0 && !inserted[index])
        {
            int partner = partners[index];
            std::vector<int>::iterator upperBound = std::find(mainChain.begin(), mainChain.end(), partner);
            std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), upperBound, pending[index]);

            mainChain.insert(pos, pending[index]);
            inserted[index] = true;
            --index;
        }
    }

    // Handle any missed pending elements
    for (size_t i = 0; i < pending.size(); ++i)
    {
        if (!inserted[i])
        {
            int partner = partners[i];
            std::vector<int>::iterator upperBound = std::find(mainChain.begin(), mainChain.end(), partner);
            std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), upperBound, pending[i]);
            mainChain.insert(pos, pending[i]);
			inserted[i] = true;
        }
    }

    // 6 - If there was a leftover element, insert it into the sorted main chain
    if (hasLeftover)
    {
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), leftOver);
        mainChain.insert(pos, leftOver);
    }

    vec = mainChain;
}

void PmergeMe::sortDeque(std::deque<int> &deq)
{
	if (deq.size() <= 1)
		return;

	bool hasLeftover = deq.size() % 2 != 0;
	int  leftOver    = 0;
	if (hasLeftover)
	{
		leftOver = deq.back();
		deq.pop_back();
	}

	std::deque<std::pair<int, int> > pairs;
	for (size_t i = 0; i < deq.size(); i += 2)
	{
		if (deq[i] < deq[i + 1])
			pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
		else
			pairs.push_back(std::make_pair(deq[i + 1], deq[i]));
	}

	// 2 - sort main chain recursively
	std::deque<int> mainChain;
	for (size_t i = 0; i < pairs.size(); ++i)
		mainChain.push_back(pairs[i].second);
	sortDeque(mainChain);

	std::deque<int> pending;
    std::deque<int> partners;
	for (size_t i = 0; i < mainChain.size(); ++i)
	{
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (mainChain[i] == pairs[j].second)
			{
				pending.push_back(pairs[j].first);
                partners.push_back(pairs[j].second);
				break;
			}
		}
	}

	mainChain.push_front(pending[0]);

	std::deque<int>  jacobsthalSeq = generateJacobsthalSequenceDeq(pending.size());
	std::deque<bool> inserted(pending.size(), false);
	inserted[0] = true;

	for (size_t i = 1; i < jacobsthalSeq.size(); ++i)
	{
		size_t index = jacobsthalSeq[i];
		if (index >= pending.size())
			index = pending.size() - 1;
		while (index > 0 && !inserted[index])
		{
            int partner = partners[index];
            std::deque<int>::iterator upperBound = std::find(mainChain.begin(), mainChain.end(), partner);
			std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), upperBound, pending[index]);
			mainChain.insert(pos, pending[index]);
			inserted[index] = true;
			--index;
		}
	}

	for (size_t i = 0; i < pending.size(); ++i)
	{
		if (!inserted[i])
		{
            int partner = partners[i];
            std::deque<int>::iterator upperBound = std::find(mainChain.begin(), mainChain.end(), partner);
			std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), upperBound, pending[i]);			mainChain.insert(pos, pending[i]);
			inserted[i] = true;
		}
	}

	if (hasLeftover)
	{
		std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), leftOver);
		mainChain.insert(pos, leftOver);
	}

	deq = mainChain;
}

void PmergeMe::sort()
{
    std::cout << "Before sorting with std::vector : ";
    for (size_t i = 0; i < _vec.size(); ++i)
        std::cout << _vec[i] << " ";
    std::cout << std::endl;

    // Time Vector
    struct timeval startVec, endVec;
    gettimeofday(&startVec, NULL);
    sortVector(_vec);
    gettimeofday(&endVec, NULL);

    double timeVec = (endVec.tv_sec - startVec.tv_sec) * 1e6 + (endVec.tv_usec - startVec.tv_usec);

    std::cout << "After sorting with std::vector :  ";
    for (size_t i = 0; i < _vec.size(); ++i)
        std::cout << _vec[i] << " ";
    std::cout << std::endl;

	std::cout << "====================" << std::endl;

	std::cout << "Before sorting with std::deque : ";
	for (std::deque<int>::iterator it = _deq.begin(); it != _deq.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

    // Time Deque
    struct timeval startDeq, endDeq;
    gettimeofday(&startDeq, NULL);
    sortDeque(_deq);
    gettimeofday(&endDeq, NULL);

    double timeDeq = (endDeq.tv_sec - startDeq.tv_sec) * 1e6 + (endDeq.tv_usec - startDeq.tv_usec);

	std::cout << "After sorting with std::deque : ";
	for (std::deque<int>::iterator it = _deq.begin(); it != _deq.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "====================" << std::endl;

    std::cout << "Time to process a range of " << _vec.size() 
              << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << _deq.size() 
              << " elements with std::deque  : " << timeDeq << " us" << std::endl;
}