#include "utils.h"

int	find_max(t_stack *s, t_move *move)
{
	int	i;
	int	current;

	i = 0;
	int max, max_idx;
	max = INT_MIN;
	while (i < s->size)
	{
		current = get_element(s, i);
		if (current > max)
		{
			max = current;
			max_idx = i;
		}
		i++;
	}
	move->target = max;
	move->target_idx = max_idx;
	return (max_idx);
}

int	find_min_idx(t_stack *s)
{
	int	i;
	int	current;

	i = 0;
	int min, min_idx;
	min = INT_MAX;
	while (i < s->size)
	{
		current = get_element(s, i);
		if (current < min)
		{
			min = current;
			min_idx = i;
		}
		i++;
	}
	return (min_idx);
}

int	find_min(t_stack *s, t_move *move)
{
	int min_idx;

	min_idx = find_min_idx(s);
	move->target_idx = min_idx;
	move->target = get_element(s, min_idx);
	return (min_idx);
}