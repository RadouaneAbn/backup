#include "../push_swap.h"

int ft_atoi_safe(t_stack *stack, char *s, int size)
{
	long int n;
	int sign;
    int i;

	sign = 0;
    i = 0;
    n = 0;
	if (s[i] == '-' || s[i] == '+')
    {
        if (s[i] == '-')
            sign = 1;
        i++;
    }
    while (s[i] && i < size)
    {
        n = n * 10 + s[i] - '0';
        if (n > (long)INT_MAX + sign)
            return (-1);
        i++;
    }
    if (sign)
        n *= -1;
    stack->stack[(stack->size)++] = (int) n;
    // printf("n: %d\n", (int)n);
    return (0);
}

int convert_args_to_int(t_stack *a, char *s)
{
    int i;
    int j;
    int status;

    i = 0;
    while (s[i])
    {
        while (s[i] && ft_isspace(s[i]))
            i++;
        j = i;
        while (s[j] && !ft_isspace(s[j]))
            j++;
        if (i != j)
        {
            status = ft_atoi_safe(a, s + i, j - i);
            if (status == -1)
                return (-1);
        }
        i = j;
    }
    return (0);
}
