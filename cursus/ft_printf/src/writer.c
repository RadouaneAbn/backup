#include "../ft_printf.h"

int writer(int *count, char *s, int slen)
{
    int i;

    i = write(1, s, slen);
    if (i == -1)
        return (error_handle(i));
    *count += i;
    return (1);
}