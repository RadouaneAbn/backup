#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_list {
    char            *s;
    struct s_list   *next;
}   t_list;

typedef struct s_buf {
    char *buffer;
    int idx;
}   t_buf;
 
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

char	*get_next_line(int fd);
char	*ft_append_str(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif
