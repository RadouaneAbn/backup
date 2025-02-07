#ifndef GARBAGE_COLLECTOR
#define GARBAGE_COLLECTOR

#include "../includes/defs.h"


typedef enum e_types {
	INT,
	CHAR,
	STRING,
	GARBAGE_COLLECTOR
}	DataType;

typedef struct s_list
{
	void						*data;
	DataType					type;
	struct s_list	*next;
}	t_list;

void	*ft_malloc(int size, int save);
void free_all();
void free_ptr(void *addr);
void	save_ptr(void *data);

#endif