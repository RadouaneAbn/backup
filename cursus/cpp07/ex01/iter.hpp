#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

/**
 * Func func is the same as void (func)(Func) TODO: some research
 */
template<typename T, typename Func>
void iter(T *arr_addr, const size_t arr_lenght, Func func)
{
    for (size_t i = 0; i < arr_lenght; i++)
        func(arr_addr[i]);
}

#endif