#include "push_swap.h"

void make_move_separate(t_stacks stack, int *move, void rv(t_stacks), void rrv(t_stacks))
{
    while (*move > 0)
    {
        rv(stack);
        (*move)--;
    }
    while (*move < 0)
    {
        rrv(stack);
        (*move)++;
    }
}

void make_move(t_stacks stack, t_move *move)
{
    if (move->a_move >= 0 && move->b_move >= 0)
    {
        while (move->a_move > 0 && move->b_move > 0)
        {
            rr(stack);
            (move->a_move)--;
            (move->b_move)--;
        }
    }
    else if (move->a_move < 0 && move->b_move < 0)
    {
        // printf("%d %d\n", move->a_move, move->b_move);
        while (move->a_move < 0 && move->b_move < 0)
        {
            rrr(stack);
            (move->a_move)++;
            (move->b_move)++;
        }
    }

    make_move_separate(stack, &move->a_move, ra, rra);
    make_move_separate(stack, &move->b_move, rb, rrb);
}

int find_target(t_stack *s, t_move *move, int order)
{
    int i;
    int current;

    i = 0;
    while (i < s->size)
    {
        current = get_element(s, i);
        if ((move->targeted > current) == order && (move->target < current) == order)
        {
                move->target = current;
                move->target_idx = i;
        }
        i++;
    }
    if (move->target_idx != -1)
        return (move->target_idx);
    // printf("no index found\n");
    if (order == DESC)
        return (find_max(s, move));
    return (find_min(s, move));
}

void calculate_score(t_stacks stack, t_move *move)
{
    int a = move->targeted_idx;
    int b = move->target_idx;
    int score;

    if (move->a_move >= 0 && move->b_move >= 0)
        score = max(a, b);
    else if (move->a_move < 0 && move->b_move < 0)
        score = max(stack.a->size - a, stack.b->size - b);
    else if (move->a_move >= 0)
        score = a + (stack.b->size - b);
    else
        score = (stack.a->size - a) + b;
    move->score = score;
}

void find_best_move_ab(t_stacks stack, t_stack *s, t_move *move)
{
    move->target_idx = find_target(s, move, DESC);
    move->a_move = find_side(stack.a, move->targeted_idx);
    move->b_move = find_side(stack.b, move->target_idx);

    calculate_score(stack, move);
}

void find_best_move_ba(t_stacks stack, t_stack *s, t_move *move)
{
    move->target_idx = find_target(s, move, ASC);
    move->a_move = find_side(stack.a, move->target_idx);
    move->b_move = find_side(stack.b, move->targeted_idx);

    calculate_score(stack, move);
}

t_move *push_best_element_ab(t_stacks stack)
{
    t_move *move;
    t_move *current;
    int i;

    i = 0;
    current = init_move(DESC);
    move = init_move(DESC);
    // while (i < stack.a->size - 3)
    while (i < stack.a->size)
    {
        clear_move(current, DESC);
        current->targeted = get_element(stack.a, i);
        current->targeted_idx = i;
        find_best_move_ab(stack, stack.b, current);
        if (current->score < move->score)
            copy_move_to(current, move);
        if (move->score == 0)
            break;
        i++;
    }
    free(current);
    return (move);
}

t_move *push_best_element_ba(t_stacks stack)
{
    t_move *move;
    t_move *current;
    int i;

    i = 0;
    current = init_move(ASC);
    move = init_move(ASC);
    while (i < stack.b->size)
    {
        current->targeted = get_element(stack.b, i);
        current->targeted_idx = i;
        find_best_move_ba(stack, stack.a, current);
        if (current->score < move->score)
            copy_move_to(current, move);
        if (move->score == 0)
            break;
        clear_move(current, ASC);
        i++;
    }
    free(current);
    return (move);
}

void organize_stack_a(t_stacks stack)
{
    int idx;
    int moves_count;

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

int sort_stack(t_stacks stack)
{
    t_move *move;

    /* push 2 elements to stack b  */
    while ((stack.a->size > 3) && (stack.b->size < 2))
        pb(stack);
    /* push the an element to the correct position */
    while (stack.a->size > 0)
    {
        move = push_best_element_ab(stack);
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

int main(int ac, char **av)
{
    t_stacks stack;
    int status;

    init_stack(&stack, ac, av);
    return (0);
    // make sure the stack is not sorted before sorting it
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
        exit (1);
    return (0);
}

// int sort_stack(t_stacks stack)
// {
//     t_move *move;
//     while ((stack.a->size > 3) && (stack.b->size < 2))
//         pb(stack);
//     while (stack.a->size > 3)
//     {
//         move = push_best_element_ab(stack);
//         make_move(stack, move);
//         pb(stack);
//         free(move);
//     }
//     short_sort_a(stack);
//     while (stack.b->size > 0)
//     {
//         move = push_best_element_ba(stack);
//         make_move(stack, move);
//         pa(stack);
//         free(move);
//     }
//     organize_stack_a(stack);
//     return (1);
// }