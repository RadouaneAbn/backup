#include "../ft_printf.h"

int error_handle(int i)
{
    static int err;

    if (i == -1)
        err = -1;
    return (err);
}