#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


# ifndef DM
#  define DM 0
# endif

typedef struct s_buf {
    char str[2048];
    size_t idx;
} t_buf;

char *get_next_line(int fd);

#endif