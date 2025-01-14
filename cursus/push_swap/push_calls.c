#include "defs.h"

void	pb(t_stacks stack, int printable)
{
	if (printable)
		printf("pb\n");
	if (stack.a->size == 0)
		return ;
	stack.b->front = (stack.b->front - 1 + stack.capacity) % stack.capacity;
	stack.b->stack[stack.b->front] = stack.a->stack[stack.a->front];
	(stack.b->size)++;
	(stack.a->size)--;
	stack.a->front = (stack.a->front + 1) % stack.capacity;
}

void	pa(t_stacks stack, int printable)
{
	if (printable)
		printf("pa\n");
	if (stack.b->size == 0)
		return ;
	stack.a->front = (stack.a->front - 1 + stack.capacity) % stack.capacity;
	stack.a->stack[stack.a->front] = stack.b->stack[stack.b->front];
	(stack.a->size)++;
	(stack.b->size)--;
	stack.b->front = (stack.b->front + 1) % stack.capacity;
}