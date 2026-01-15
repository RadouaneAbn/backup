#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <string>

template <typename T>
class Array
{
    T *_array;
    unsigned int _array_capasity;
public:
    Array(void);
    Array( unsigned int n );
    Array(const Array &old_array);
    Array &operator=(const Array &old_array);
    ~Array(void);

    T& operator[](unsigned int i);

    unsigned int size(void) const;

    class IndexOutOfBound : public std::exception
    {
        const char* what(void) const throw();
    };
};

#include "Array.tpp"

#endif