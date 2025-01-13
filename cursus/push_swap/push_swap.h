#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "defs.h"

#define TOP_SIDE 1
#define BOTTOM_SIDE 2

# define ASC 0
# define DESC 1

int sort_stack(t_stacks stack);
int is_not_sorted(t_stack *stack);
int short_sort_a(t_stacks s);

void s_print(t_stack *a, t_stack *b);

/* Stack call functions */

t_move *init_move();
void clear_move(t_move *move);
void copy_move_to(t_move *src, t_move *dst);

int find_max(t_stack *s, t_move *move);
int find_min(t_stack *s, t_move *move);
int find_min_idx(t_stack *s);

int short_sort_a(t_stacks s);
int find_side(t_stack *s, int idx);

t_move *push_best_element(t_stacks stack);
void make_move(t_stacks stack, t_move *move);

// int all_args_are_valide_phase1(char *s);
// int notvalid_number(char *s);
// int ft_isnum(int c);
// int ft_isspace(int c);
void clean_exit(void *p1, void *p2, void *p3, void *p4);
int get_correct_count(int ac, char **av);
int get_arg_count(char *s);
// int convert_args_to_int(t_stack *a, char *s);

#endif