#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

#define TOP_SIDE 1
#define BOTTOM_SIDE 2


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

# define ASC 0
# define DESC 1

enum {
    SWAP_A = 1,
    SWAP_B,
    SWAP_AB
};

int get_element(t_stack *stack, int idx);
int sort_stack(t_stacks stack);
int is_not_sorted(t_stack *stack);
int short_sort_a(t_stacks s);

void print_stack(t_stacks stack);
void print_stack_solo(t_stack *stack, char stack_name);
void print_move(t_move *move);


void s_print(t_stack *a, t_stack *b);

/* Stack call functions */
void init_stack(t_stacks *stack, int ac, char **av);

void pa(t_stacks stack);
void pb(t_stacks stack);

void sa(t_stacks stack);
void sb(t_stacks stack);
void ss(t_stacks stack);

void ra(t_stacks stack);
void rb(t_stacks stack);
void rr(t_stacks stack);

void rra(t_stacks stack);
void rrb(t_stacks stack);
void rrr(t_stacks stack);

t_move *init_move(int order);
void copy_move_to(t_move *src, t_move *dst);
void clear_move(t_move *move, int order);

int find_max(t_stack *s, t_move *move);
int find_min(t_stack *s, t_move *move);
int find_min_idx(t_stack *s);
int find_side(t_stack *s, int idx);
int max(int a, int b);


#endif