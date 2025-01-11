#include "push_swap.h"

int get_element(t_stack *stack, int idx)
{
    if (idx < 0)
        return (stack->stack[(stack->rear + idx + stack->capacity) % stack->capacity]);
    return (stack->stack[(stack->front + idx) % stack->capacity]);
}

/**
 * peek: Get the top element in a stack
 * Return:
 *  The value of the top element if a stack
 */

int peek(t_stack *stack)
{
    return (stack->stack[stack->front]);
}

int stack_isempty(t_stack *stack)
{
    return (stack->size == 0);
}

/**
 * ab_cmp: Compaires the top of both stacks
 * Return:
 *  0: if `a` is empty or if the top of `a` is bigger than top of `b`
 *  1: if `b` is empty ot if the top of `b` is bigger than top of `a`
 */

int ab_cmp(t_stacks stack)
{
    if (stack_isempty(stack.a))
        return (0);
    else if (stack_isempty(stack.b))
        return (1);
    if (peek(stack.a) < peek(stack.b))
        return (1);
    return (0);
}

int stack_cmp(t_stacks stack)
{
    int result;

    result = 0;
    if (stack.a->size > 1)
    {
        if (get_element(stack.a, 0) > get_element(stack.a, 1))
            result += SWAP_A;
    }
    if (stack.b->size > 1)
    {
        if (get_element(stack.b, 0) < get_element(stack.b, 1))
            result += SWAP_B;
    }
    return (result);
}

int is_not_sorted(t_stack *stack)
{
    int i;

    i = 0;
    /* Stack empty */
    if (stack->size == 0)
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

// void sort_stack(t_stacks stack)
// {
//     int not_sorted = 1;
//     int tmp_result;
//     while (is_not_sorted(stack.a))
//     {
//         tmp_result = stack_cmp(stack);
//         if (tmp_result == SWAP_A)
//             sa(stack);
//         else if (tmp_result == SWAP_B)
//             sb(stack);
//         else if (tmp_result == SWAP_AB)
//             ss(stack);
//         else if (stack_isempty(stack.b))
//             pb(stack);
//     }
// }


/**
 * short_sort: Sort a stack of size 3 or less
 * Note:
 *  The sorting is done by making sure that the highest
 *  number is in the buttom of the stack
 *  then swith the first two elements if needed
 */

int short_sort_a(t_stacks s)
{
    // int a = get_element(s.a, 0);
    // int b = get_element(s.a, 1);
    // int c = get_element(s.a, 2);

    if (get_element(s.a, 0) > get_element(s.a, 1)
        && get_element(s.a, 0) > get_element(s.a, 2) )
        ra(s);
    else if (get_element(s.a, 1) > get_element(s.a, 0)
        && get_element(s.a, 1) > get_element(s.a, 2))
        rra(s);
    if (get_element(s.a, 0) > get_element(s.a, 1))
        sa(s);
    return (1);
}