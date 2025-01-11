#include "../push_swap.h"

t_move *init_move(int order)
{
    t_move *move;

    move = malloc(sizeof(t_move));
    if (order == ASC)
        move->target = INT_MAX;
    else
        move->target = INT_MIN;
    move->target_idx = -1;
    move->targeted = 0;
    move->targeted_idx = 0;
    move->a_move = 0;
    move->b_move = 0;
    move->score = INT_MAX;

    return (move);
}


void clear_move(t_move *move, int order)
{
    if (order == ASC)
        move->target = INT_MAX;
    else
        move->target = INT_MIN;
    move->target_idx = -1;
    move->targeted = 0;
    move->targeted_idx = 0;
    move->a_move = 0;
    move->b_move = 0;
    move->score = INT_MAX;
}

void copy_move_to(t_move *src, t_move *dst)
{
    dst->target = src->target;
    dst->target_idx = src->target_idx;
    dst->targeted = src->targeted;
    dst->targeted_idx = src->targeted_idx;
    dst->a_move = src->a_move;
    dst->b_move = src->b_move;
    dst->score = src->score;
}

int find_side(t_stack *s, int idx)
{
    // int size;
    int middle;
    if (s->size % 2 == 0)
        middle = s->size / 2 - 1; // WARNING if size == 0
    else
        middle = s->size / 2;
    if (idx <= middle)
        return (idx);
    else
        return (-(s->size - idx));
}

int max(int a, int b)
{
    if (a > b)
        return (a);
    return (b);
}