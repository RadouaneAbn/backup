#ifndef DEBUG_H
#define DEBUG_H

#include "../defs.h"

/* Debuging */
void print_stack(t_stacks stack);
void print_stack_solo(t_stack *stack, char stack_name);
void print_move(t_move *move);

#endif