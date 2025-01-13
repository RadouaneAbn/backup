#ifndef DEFS_H
#define DEFS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
    int *stack;
    int size;
    int front;
    int rear;
    int capacity;
}   t_stack;

typedef struct s_stacks
{
    t_stack *a;
    t_stack *b;
    int capacity;
} t_stacks;

typedef struct s_move {
    int target;
    int target_idx;
    int targeted;
    int targeted_idx;
    int a_move;
    int b_move;
    int score;
} t_move;

#endif