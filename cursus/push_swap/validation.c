#include "defs.h"
#include "utils.h"

int	notvalid_number(char *s)
{
	if (*s == '-')
		s++;
	while (*s)
	{
		if (ft_isnum(*s) == 0)
			return (1);
		s++;
	}
	return (0);
}

int	all_args_are_valide_phase1(char *s)
{
	int	i;

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

int	already_in_stack(t_stack *s, int n)
{
	int	i;

	i = 0;
	while (i < s->size)
	{
		if (get_element(s, i) == n)
			return (1);
		i++;
	}
	return (0);
}

int	is_not_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	/* Stack empty */
	if (stack_isempty(stack))
		return (0);
	/* Stack not full (which means stack is not sorted) */
	if (stack->size != stack->capacity)
		return (1);
	while (i < stack->size - 1)
	{
		if (get_element(stack, i) > get_element(stack, i + 1))
			return (1);
		i++;
	}
	return (0);
}
