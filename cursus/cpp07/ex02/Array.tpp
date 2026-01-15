#include "Array.hpp"

template <typename T>
Array<T>::Array(void) : _array(NULL), _array_capasity(0)
{
}

template <typename T>
Array<T>::Array( unsigned int n) : _array(new T[n]), _array_capasity(n)
{
}

template <typename T>
Array<T>::Array(const Array &old_array)
{
    _array_capasity = old_array._array_capasity;
    _array = new T[_array_capasity];
    for (unsigned int i = 0; i < _array_capasity; i++)
        _array[i] = old_array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &old_array)
{
    if (*this != old_array)
    {
        if (_array != NULL)
            delete[] _array;
        _array_capasity= old_array._array_capasity;
        _array = new T[_array_capasity];
        for (unsigned int i = 0; i < _array_capasity; i++)
            _array[i] = old_array[i];
    }
    return (*this);
}

template <typename T>
Array<T>::~Array(void)
{
    if (_array != NULL)
        delete[] _array;
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
    if (i >= _array_capasity)
        throw IndexOutOfBound();
    return _array[i];
}

template <typename T>
unsigned int Array<T>::size(void) const {
    return _array_capasity;
}

template <typename T>
const char* Array<T>::IndexOutOfBound::what(void) const throw() {
    return "Index out of bound";
}
