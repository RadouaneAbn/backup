#include "../push_swap.h"

void clean_exit(void *p1, void *p2, void *p3, void *p4)
{
    if (p1)
        free(p1);
    if (p2)
        free(p2);
    if (p3)
        free(p3);
    if (p4)
        free(p4);
    printf("Error\n");
    exit(1);
}