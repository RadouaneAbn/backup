#include "defs.h"

void	ra(t_stacks stack, int printable)
{
	if (printable)
		printf("ra\n");
	if (stack.a->size < 2)
		return ;
	stack.a->stack[stack.a->rear] = stack.a->stack[stack.a->front];
	stack.a->front = (stack.a->front + 1) % stack.capacity;
	stack.a->rear = (stack.a->rear + 1) % stack.capacity;
}

void	rb(t_stacks stack, int printable)
{
	if (printable)
		printf("rb\n");
	if (stack.b->size < 2)
		return ;
	stack.b->stack[stack.b->rear] = stack.b->stack[stack.b->front];
	stack.b->front = (stack.b->front + 1) % stack.capacity;
	stack.b->rear = (stack.b->rear + 1) % stack.capacity;
}

void	rr(t_stacks stack, int printable)
{
	if (printable)
		printf("rr\n");
	if (stack.a->size > 1)
	{
		stack.a->stack[stack.a->rear] = stack.a->stack[stack.a->front];
		stack.a->front = (stack.a->front + 1) % stack.capacity;
		stack.a->rear = (stack.a->rear + 1) % stack.capacity;
	}
	if (stack.b->size > 1)
	{
		stack.b->stack[stack.b->rear] = stack.b->stack[stack.b->front];
		stack.b->front = (stack.b->front + 1) % stack.capacity;
		stack.b->rear = (stack.b->rear + 1) % stack.capacity;
	}
	// ra(stack);
	// rb(stack);
}