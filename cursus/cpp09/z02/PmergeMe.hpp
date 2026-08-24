#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <sys/time.h>
#include <vector>

class PmergeMe
{
  public:
    PmergeMe();
    ~PmergeMe();

    void parseInput(int argc, char **argv);
    void sort();

    std::vector<int> _vec;
    std::deque<int>  _deq;

  private:
    std::vector<int> generateJacobsthalSequenceVec(int n);
    std::deque<int> generateJacobsthalSequenceDeq(int n);

    void sortVector(std::vector<int> &vec);
    void sortDeque(std::deque<int> &deq);

    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
};

#endif