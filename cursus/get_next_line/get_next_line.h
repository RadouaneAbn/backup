#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_buf {
    char buffer[1024];
    int idx;
}   t_buf;
 
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

char	*get_next_line(int fd);
int ft_append_str(char **dest, char *src);
char	*ft_substr(char *s, unsigned int start, size_t len);
int     ft_appendto_buffer(char *s, t_buf *b, char **line);
size_t ft_strlen(char *s);

#endif
