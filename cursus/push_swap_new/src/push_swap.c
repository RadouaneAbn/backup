/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:25:55 by rabounou          #+#    #+#             */
/*   Updated: 2025/01/15 13:07:52 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operations.h"
#include "../includes/push_swap.h"
#include "../includes/utils.h"

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
			ra(stack, 1);
			moves_count--;
		}
	}
	else
	{
		while (moves_count < 0)
		{
			rra(stack, 1);
			moves_count++;
		}
	}
}

int	sort_stack(t_stacks stack)
{
	t_move	*move;

	while ((stack.a->size > 3) && (stack.b->size < 2))
		pb(stack, 1);
	while (stack.a->size > 0)
	{
		move = push_best_element(stack);
		make_move(stack, move);
		pb(stack, 1);
		free(move);
	}
	while (stack.b->size > 0)
		pa(stack, 1);
	organize_stack_a(stack);
	return (1);
}

t_chunks *create_chunks(t_stacks stacks)
{
	t_chunks *chunks;
	int i;

	chunks = malloc(sizeof(t_chunks));
	if (chunks == NULL)
		return (NULL);
	chunks->size = stacks.capacity;
	if (chunks->size < 100)
		chunks->chunksize = chunks->size / SMALL_CHUNK;
	else
		chunks->chunksize = chunks->size / BIG_CHUNK;
	chunks->arr = malloc(sizeof(int) * chunks->size);
	if (chunks->arr == NULL)
		return (free(chunks), NULL);
	i = 0;
	while (i < chunks->size)
	{
		chunks->arr[i] = get_element(stacks.a, i);
		i++;
	}
	return (chunks);
}

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void insertion_sort(t_chunks *chunks)
{
	int *arr;
	int start;
	int i;

	arr = chunks->arr;
	start = 0;
	i = 1;
	while (i < chunks->size)
	{
		start = i;
		while (start > 0 && arr[start] < arr[start - 1])
		{
			swap(&arr[start], &arr[start - 1]);
			start--;
		}
		i++;
	}
}

int find_best_target(t_stack *a, int chunk_n, t_chunks *chunks)
{
	int start;
	int end;
	int i;
	int best_idx;

	start = chunk_n * chunks->chunksize;
	end = (chunk_n + 1) * chunks->chunksize;
	i = 0;
	while (i < a->size)
	{
		if (element_in_chunk(get_element(a, i), start, end));
	}
}

// 8 6 4 9 6 4 5 9 0 5 3 7 9 

int sort_stack_new(t_stacks stacks)
{
	t_chunks *chunks;
	int chunk_n;
	int best_idx;

	chunks = create_chunks(stacks);
	insertion_sort(chunks);

	chunk_n = 0;
	best_idx = -1;
	while (stacks.a->size != 0)
	{
		best_idx = find_best_target(stacks.a, chunk_n, chunks);
	}

	return (1);
}

int	main(int ac, char **av)
{
	t_stacks	stack;
	int			status;

	status = 0;
	if (ac == 1)
		return (0);
	status = init_stack(&stack, ac, av);
	if (status == 0)
		return (status);
	if (is_not_sorted(stack.a))
	{
		if (stack.capacity <= 3)
			status = short_sort_a(stack);
		else if (stack.capacity <= 6)
			status = short_sort_6(stack);
		else
			status = sort_stack_new(stack);
			// status = sort_stack(stack);
	}
	free_stacks(stack);
	if (status == -1)
		exit(1);
	return (0);
}
