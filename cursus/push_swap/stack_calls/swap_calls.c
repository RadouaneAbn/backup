#include "../push_swap.h"

void sb(t_stacks stack)
{
    int tmp;

    printf("sb\n");
    if (stack.b->size < 2)
        return ;
    tmp = stack.b->stack[stack.b->front];
    stack.b->stack[stack.b->front] = stack.b->stack[(stack.b->front + 1) % stack.capacity];
    stack.b->stack[(stack.b->front + 1) % stack.capacity] = tmp;
}

void sa(t_stacks stack)
{
    int tmp;

    printf("sa\n");
    if (stack.a->size < 2)
        return ;
    tmp = stack.a->stack[stack.a->front];
    stack.a->stack[stack.a->front] = stack.a->stack[(stack.a->front + 1) % stack.capacity];
    stack.a->stack[(stack.a->front + 1) % stack.capacity] = tmp;
}

void ss(t_stacks stack)
{
    printf("ss\n");

    int tmp;
    if (stack.b->size < 2)
    {
        tmp = stack.b->stack[stack.b->front];
        stack.b->stack[stack.b->front] = stack.b->stack[(stack.b->front + 1) % stack.capacity];
        stack.b->stack[(stack.b->front + 1) % stack.capacity] = tmp;
    }

    if (stack.a->size < 2)
    {
        tmp = stack.a->stack[stack.a->front];
        stack.a->stack[stack.a->front] = stack.a->stack[(stack.a->front + 1) % stack.capacity];
        stack.a->stack[(stack.a->front + 1) % stack.capacity] = tmp;
    }
    // sa(stack);
    // sb(stack);
}