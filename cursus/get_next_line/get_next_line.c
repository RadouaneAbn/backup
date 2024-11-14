#include "get_next_line.h"

int newline_found(char *s)
{
    int i;

    if (s == NULL)
        return (0);
    i = 0;
    while (s[i] && s[i] != '\n')
        i++;
    return (s[i] == '\n');
}

void read_line(char **last_string, int fd)
{
    ssize_t read_len;
    char *s;
    
    s = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (s == NULL)
        return ;
    read_len = read(fd, s, BUFFER_SIZE);
    if (read_len <= 0)
    {
        // free(s);
        return ;
    }
    s[read_len] = 0;
    *last_string = s;
}

char *clear_line(char **s)
{
    int i;
    int j;
    int k;
    char *new_str;
    char *last_str;

    i = 0;
    if (*s == NULL)
        return (NULL);
    while ((*s)[i] && (*s)[i] != '\n')
        i++;
    // printf("[%d] {%s}\n", i, *s);
    new_str = ft_substr(*s, 0, i);
    // printf("line 1: {%s}\n", new_str);
    j = i + 1;
    while ((*s)[j])
        j++;
    last_str = ft_substr(*s, i + 1, j);
    // printf("line 2: {%s}\n", last_str);
    // printf("done\n");
    // free(*s);
    *s = last_str;
    return (new_str);
}

char	*get_next_line(int fd)
{
    static char last_string[BUFFER_SIZE];
    char *tmp;
    char *result;
    int size;
    char *str_before_nl;

    result = NULL;
    while (!newline_found(last_string))
    {
        printf("1");
        result = ft_append_str(result, last_string);
        read_line(last_string, fd);
        if (last_string == NULL)
            break;
    }
    str_before_nl = clear_line(last_string);
    result = ft_append_str(result, str_before_nl);
    return (result);
}
