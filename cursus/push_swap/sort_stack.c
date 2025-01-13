#include "operations.h"
#include "utils.h"

/**
 * short_sort: Sort a stack of size 3 or less
 * Note:
 *  The sorting is done by making sure that the highest
 *  number is in the buttom of the stack
 *  then swith the first two elements if needed
 */

int	short_sort_a(t_stacks s)
{
	if (get_element(s.a, 0) > get_element(s.a, 1) && get_element(s.a,
			0) > get_element(s.a, 2))
		ra(s);
	else if (get_element(s.a, 1) > get_element(s.a, 0) && get_element(s.a,
			1) > get_element(s.a, 2))
		rra(s);
	if (get_element(s.a, 0) > get_element(s.a, 1))
		sa(s);
	return (1);
}