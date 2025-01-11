#include "../push_swap.h"

static int notvalid_number(char *s)
{
    if (*s == '-')
        s++;
    while (*s)
    {
        if (*s < '0' || *s > '9')
            return (1);
        s++;
    }
    return (0);
}

static int ft_atoi_safe(t_stack *stack, char *s)
{
	long int n;
	int sign;
    int i;

    if (notvalid_number(s))
    {
        return (-1);
    }
	sign = 0;
    i = 0;
    n = 0;
	if (s[i] == '-' || s[i] == '+')
    {
        if (s[i] == '-')
            sign = 1;
        i++;
    }
    while (s[i])
    {
        n = n * 10 + s[i] - '0';
        if (n > (long)INT_MAX + sign)
        {
            // printf("[%ld]\n", n);
            return (-1);
        }
        i++;
    }
    if (sign)
        n *= -1;
    stack->stack[stack->size++] = n;
    return (1);
}

int init_stack(t_stacks *stack, int ac, char **av)
{
    int i;

    i = 1;
    stack->a = (t_stack *)malloc(sizeof(t_stack));
    stack->a->stack = malloc(sizeof(int) * (ac - 1));
    stack->a->size = 0;
    stack->a->front = 0;
    /*---------------------------------------------*/
    stack->b = (t_stack *)malloc(sizeof(t_stack));
    stack->b->stack = malloc(sizeof(int) * (ac - 1));
    stack->b->size = 0;
    stack->b->front = 0;
    /*---------------------------------------------*/
    stack->capacity = ac - 1;
    stack->a->capacity = ac - 1;
    stack->b->capacity = ac - 1;
    while (i < ac)
    {
        if (ft_atoi_safe(stack->a, av[i]) == -1)
            return (-1);
        i++;
    }
    stack->a->rear = stack->a->size % stack->a->capacity;
    stack->b->rear = stack->b->size % stack->b->capacity;
    return (1);
}
