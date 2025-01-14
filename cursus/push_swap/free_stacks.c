#include "defs.h"

void free_stacks(t_stacks stacks)
{
    free(stacks.a->stack);
    free(stacks.b->stack);
    free(stacks.a);
    free(stacks.b);
}