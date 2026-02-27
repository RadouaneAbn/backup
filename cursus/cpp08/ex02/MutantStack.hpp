#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:

    typedef typename std::stack<T>::container_type::iterator iterator; 
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    MutantStack(void);
    ~MutantStack(void);
    MutantStack(const MutantStack &oldObj);
    MutantStack &operator=(const MutantStack &oldObj);

    iterator begin();
    iterator end();

    const_iterator begin() const;
    const_iterator end() const;
};

#include "MutantStack.tpp"

#endif