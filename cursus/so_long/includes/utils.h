#ifndef UTILS_H
#define UTILS_H

# include "defs.h"
# include "../libft/libft.h"

int file_is_dot_ber(char *file_path);
int open_file(char *map_path);

void exit_error(int exit_status, char *msg);

#endif