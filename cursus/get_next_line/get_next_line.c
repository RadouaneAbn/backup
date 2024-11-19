#include "get_next_line.h"

int newline_found(char *s)
{
    int i;

    i = 0;
    while (s[i] && s[i] != '\n')
        i++;
    return (s[i] == '\n');
}

void clear_line(char *s)
{
    int i;
    int j;

    i = 0;
    while (s[i] && s[i] != '\n')
        i++;
    j = i + 1;
    i = 0;
    while (s[j])
        s[i++] = s[j++];
    s[i] = 0;
}

char *get_next_line(int fd)
{
    static char last[BUFFER_SIZE];
    t_buf b;
    char *line;
    ssize_t size_read;

    b.idx = 0;
    b.buffer[0] = 0;
    line = NULL;
    while (!newline_found(last))
    {
        ft_appendto_buffer(last, &b, &line);
        size_read = read(fd, last, BUFFER_SIZE);
        if (size_read <= 0)
            break;
    }
    if (newline_found(last))
    {
        ft_appendto_buffer(last, &b, &line);
        ft_append_str(&line, b.buffer);
        clear_line(last);
    }
    return (line);
}
