#ifndef GARBAGE_COLLECTOR
#define GARBAGE_COLLECTOR

#include "../includes/defs.h"

// #define SAVE 1
// #define NO_SAVE 0

typedef enum e_types {
	INT,
	CHAR,
	STRING,
	GARBAGE_COLLECTOR
}	DataType;

typedef struct s_node
{
	void						*data;
	struct s_node	*next;
}	t_node;

void	*ft_malloc(int size);
void free_all();
void free_ptr(void *addr);
void	save_ptr(void *data);
void	*ft_smalloc(int size);

#endif