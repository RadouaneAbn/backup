#include "stdlib.h"

#define FAIL_RATE 10

void *ft_malloc_test(int size)
{
    static int i = 0;

    i++;
    if (i < FAIL_RATE)
        return malloc(size);
    return (NULL);
}
