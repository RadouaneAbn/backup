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

void clean_exit(void *p1, void *p2, void *p3, void *p4)
{
    if (p1)
        free(p1);
    if (p2)
        free(p2);
    if (p3)
        free(p3);
    if (p4)
        free(p4);
    printf("Error\n");
    exit(1);
}

void allocate_stack(t_stacks *stack, int args_count)
{
    stack->a = (t_stack *)malloc(sizeof(t_stack));
    if (stack->a == NULL)
        clean_exit(NULL, NULL, NULL, NULL);
    /*----------------------------------------------*/
    stack->a->stack = malloc(sizeof(int) * (args_count));
    if (stack->a->stack == NULL)
        clean_exit(stack->a, NULL, NULL, NULL);
    /*----------------------------------------------*/
    /*----------------------------------------------*/
    stack->b = (t_stack *)malloc(sizeof(t_stack));
    if (stack->b == NULL)
        clean_exit(stack->a->stack, stack->a, NULL, NULL);
    /*----------------------------------------------*/
    stack->b->stack = malloc(sizeof(int) * (args_count));
    if (stack->b->stack == NULL)
        clean_exit(stack->b, stack->a->stack, stack->a, NULL);
}

int ft_isspace(int c)
{
    if (c == ' ' || c == '\t' || c == '\n'
        || c == '\v' || c == '\f' || c == '\r')
        return (1);
    return (0);
}

int ft_isnum(int c)
{
    if ((c >= '0' && c <= '9'))
        return (1);
    return (0);
}

int all_args_are_valide_phase1(char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (s[i] == '-')
        {
            if (i > 0 && !ft_isspace(s[i - 1]))
                return (-1);
            if (s[i] && !ft_isnum(s[i + 1]))
                return (-1);
        }
        else if (ft_isnum(s[i]) == 0 && ft_isspace(s[i]) == 0)
            return (-1);
        i++;
    }
    return (0);
}

int get_arg_count(char *s)
{
    int i, j;
    int count;

    i = 0;
    count = 0;
    if (all_args_are_valide_phase1(s) == -1)
    {
        // printf("Phase 1 check failed\n");
        return (-1);
    }
    while (s[i])
    {
        while (s[i] && ft_isspace(s[i]))
            i++;
        j = i;
        while (s[j] && !ft_isspace(s[j]))
            j++;
        if (i != j)
            count++;
        i = j;
    }
    return (count);
}

int get_correct_count(int ac, char **av)
{
    int i;
    int count;
    int current_count;

    i = 1;
    count = 0;
    while (i < ac)
    {
        current_count = get_arg_count(av[i++]);
        if (current_count == -1)
            return (-1);
        count += current_count;
    }
    return (count);
}

void init_stack(t_stacks *stack, int ac, char **av)
{
    int i;
    int elements_count;

    i = 1;
    elements_count = get_correct_count(ac, av);
    // printf("count: %d\n", elements_count);
    if (elements_count == -1)
        clean_exit(NULL, NULL, NULL, NULL);
    allocate_stack(stack, elements_count);
    stack->capacity = elements_count;
    stack->a->capacity = elements_count;
    stack->a->size = 0;
    stack->a->front = 0;
    /*----------------------------------------*/
    stack->b->capacity = elements_count;
    stack->b->size = 0;
    stack->b->front = 0;
    while (i < ac)
    {
        if (ft_atoi_safe(stack->a, av[i]) == -1)
            clean_exit(stack->a, stack->a->stack, stack->b, stack->b->stack);
        i++;
    }
    stack->a->rear = stack->a->size % stack->a->capacity;
    stack->b->rear = stack->b->size % stack->b->capacity;
}
