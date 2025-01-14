#ifndef CHECKER_H
#define CHECKER_H

#include "../utils.h"
#include "../operations.h"
#include "../get_next_line/get_next_line.h"

enum n_op {
    PA,
    PB,
    SA,
    SB,
    SS,
    RA,
    RB,
    RR,
    RRA,
    RRB,
    RRR,
    OP_COUNT
};

typedef void (*t_instruct)(t_stacks, int);

int     ft_strcmp(const char *s1, const char *s2);

#endif