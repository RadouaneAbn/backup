#ifndef GARBAGE_COLLECTOR
# define GARBAGE_COLLECTOR

# include "../includes/defs.h"

void	*ft_malloc(int size);
void	free_all(void);
void	free_ptr(void *addr);
void	save_ptr(void *data);
void	*ft_smalloc(int size);

#endif