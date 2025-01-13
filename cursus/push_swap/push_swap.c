#include "operations.h"
#include "push_swap.h"
#include "utils.h"

void	organize_stack_a(t_stacks stack)
{
	int	idx;
	int	moves_count;

	idx = find_min_idx(stack.a);
	moves_count = find_side(stack.a, idx);
	if (moves_count >= 0)
	{
		while (moves_count > 0)
		{
			ra(stack);
			moves_count--;
		}
	}
	else
	{
		while (moves_count < 0)
		{
			rra(stack);
			moves_count++;
		}
	}
}

int	sort_stack(t_stacks stack)
{
	t_move	*move;

	/* push 2 elements to stack b  */
	while ((stack.a->size > 3) && (stack.b->size < 2))
		pb(stack);
	/* push the an element to the correct position */
	while (stack.a->size > 0)
	{
		move = push_best_element(stack);
		make_move(stack, move);
		pb(stack);
		free(move);
	}
	/* push back all elements to stack a */
	while (stack.b->size > 0)
		pa(stack);
	/* rotate the stack to make the smallest element in the top */
	organize_stack_a(stack);
	return (1);
}

int	main(int ac, char **av)
{
	t_stacks	stack;
	int			status;

	init_stack(&stack, ac, av);
	if (is_not_sorted(stack.a) == 0)
		return (0);
	if (stack.capacity <= 3)
	{
		/* WARNNING: 2 elem is not working */
		status = short_sort_a(stack);
	}
	else
		status = sort_stack(stack);
	if (status == -1)
		exit(1);
	return (0);
}
