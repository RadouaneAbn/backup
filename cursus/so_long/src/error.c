#include "../includes/so_long.h"
#include "../includes/get_next_line.h"
#include "../includes/utils.h"
#include "../libft/libft.h"
#include "../includes/garbage_collector.h"

void exit_error(int exit_status, char *msg)
{
	free_all();
    write(2, "Error\n^^^^^\\ ", 13);
    if (msg == NULL)
        perror(NULL);
    else
	    write(2, msg, ft_strlen(msg));
	exit(exit_status);
}