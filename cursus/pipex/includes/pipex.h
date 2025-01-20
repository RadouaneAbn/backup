#ifndef PIPEX_H
#define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "../libft/libft.h"

typedef struct s_cmd_list {
    char ***cmd_list;
    int cmd_count;
} t_cmd_list;

#endif
