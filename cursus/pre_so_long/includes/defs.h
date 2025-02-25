#ifndef DEFS_H
#define DEFS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define FALSE 0
#define TRUE 1


# define INV_MAP_ST 111
# define READ_ERROR_ST 112
# define OPEN_ERROR_ST 113
# define WRONG_EXT_ST 114
# define WRONG_EXT_MSG "Wrong file extention [file.ber]"
# define INV_MAP_MSG "Invalid Map\n"
# define READ_ERROR_MSG "Cannot read file\n"
# define OPEN_ERROR_MSG "Cannot open file\n"

// typedef struct s_list
// {
//     char *line;
//     struct s_list *next;
// } t_list;



#endif
