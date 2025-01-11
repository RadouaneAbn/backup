#include "../push_swap.h"

void rra(t_stacks stack)
{
    printf("rra\n");
    if (stack.a->size < 2)
        return ;

    stack.a->front = (stack.a->front - 1 + stack.capacity) % stack.capacity;
    stack.a->rear = (stack.a->rear - 1 + stack.capacity) % stack.capacity;
    stack.a->stack[stack.a->front] = stack.a->stack[stack.a->rear];
}

void rrb(t_stacks stack)
{
    printf("rrb\n");
    if (stack.b->size < 2)
        return ;

    stack.b->front = (stack.b->front - 1 + stack.capacity) % stack.capacity;
    stack.b->rear = (stack.b->rear - 1 + stack.capacity) % stack.capacity;
    stack.b->stack[stack.b->front] = stack.b->stack[stack.b->rear];
}

void rrr(t_stacks stack)
{
    printf("rrr\n");

    if (stack.a->size > 1)
    {
        stack.a->front = (stack.a->front - 1 + stack.capacity) % stack.capacity;
        stack.a->rear = (stack.a->rear - 1 + stack.capacity) % stack.capacity;
        stack.a->stack[stack.a->front] = stack.a->stack[stack.a->rear];
    }

    if (stack.b->size > 1)
    {
        stack.b->front = (stack.b->front - 1 + stack.capacity) % stack.capacity;
        stack.b->rear = (stack.b->rear - 1 + stack.capacity) % stack.capacity;
        stack.b->stack[stack.b->front] = stack.b->stack[stack.b->rear];
    }
    // rra(stack);
    // rrb(stack);
}