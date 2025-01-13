#include "defs.h"

int	stack_isempty(t_stack *stack)
{
	return (stack->size == 0);
}

int	get_element(t_stack *stack, int idx)
{
	if (idx < 0)
		return (stack->stack[(stack->rear + idx + stack->capacity)
			% stack->capacity]);
	return (stack->stack[(stack->front + idx) % stack->capacity]);
}
