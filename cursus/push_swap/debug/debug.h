#ifndef DEBUG_H
#define DEBUG_H

#include "../includes/defs.h"

/* Debuging */
void print_stack(t_stack_group stack);
void print_stack_solo(t_stack *stack, char stack_name);
void print_move(t_move *move);

#endif