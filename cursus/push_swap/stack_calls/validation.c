#include "../push_swap.h"

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

int notvalid_number(char *s)
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

