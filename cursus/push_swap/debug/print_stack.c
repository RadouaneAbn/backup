#include "debug.h"

void	print_move(t_move *move)
{
	printf("The best move found:\n");
	printf("score: %d\n", move->score);
	printf("a: [%d]-> %d\n", move->targeted_idx, move->targeted);
	printf("b: [%d]-> %d\n", move->target_idx, move->target);
	if (move->a_move >= 0)
		printf("a at the UPPER half\n");
	else
		printf("a at the BOTTOM half\n");
	if (move->b_move >= 0)
		printf("b at the UPPER half\n");
	else
		printf("b at the BOTTOM half\n");
}

void	s_print(t_stack *a, t_stack *b)
{
	int	i;

	i = -1;
	while (++i < a->size)
		printf("a-> %d\n", a->stack[a->front + i]);
	i = -1;
	while (++i < b->size)
		printf("b-> %d\n", b->stack[b->front + i]);
}

void	print_stack_ab(t_stack *a, t_stack *b, int capacity)
{
	int	i;
	int	max;
	int	x;
	int	y;

	if (a->size > b->size)
		max = a->size;
	else
		max = b->size;
	x = 0;
	y = 0;
	i = 0;
	while (i < max)
	{
		if (i + a->size >= max)
			printf("# % 11d #    ", a->stack[(a->front + x++) % capacity]);
		else
			printf("#             #    ");
		if (i + b->size >= max)
			printf("# % 11d #\n", b->stack[(b->front + y++) % capacity]);
		else
			printf("#             #\n");
		i++;
	}
}

void	print_stack_single(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		printf("# % 11d #\n", stack->stack[(stack->front + i)
			% stack->capacity]);
		i++;
	}
}

void	print_stack_solo(t_stack *stack, char stack_name)
{
	printf("#=============#\n");
	print_stack_single(stack);
	printf("#=============#\n");
	printf("#=  stack %c  =#\n", stack_name);
	printf("#=============#\n\n");
}

void	print_stack(t_stack_group stack)
{
	printf("#=============#    #=============#\n");
	print_stack_ab(stack.a, stack.b, stack.capacity);
	printf("#=============#    #=============#\n");
	printf("#=  stack a  =#    #=  stack b  =#\n");
	printf("#=============#    #=============#\n\n");
}
