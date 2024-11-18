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
        {
            printf("[%ld] DONE!!!\n", size_read);
            break;
        }
    }
    if (newline_found(last))
    {
        ft_appendto_buffer(last, &b, &line);
        ft_append_str(&line, b.buffer);
        clear_line(last);
    }
    return (line);
}

// char	*get_next_line(int fd)
// {
//     static char last_string[BUFFER_SIZE + 1];
//     char *tmp;
//     char *result;
//     int size;
//     char *str_before_nl;

//     result = NULL;
//     while (!newline_found(last_string))
//     {
//         result = ft_append_str(result, last_string);
//         // read_line(&last_string, fd);
//         if (read_line(last_string, fd) == 0)
//             break;
//     }
//     str_before_nl = clear_line(last_string);
//     result = ft_append_str(result, str_before_nl);
//     // printf("\n\nnl: [%s]\n[%s]\n\n", str_before_nl, last_string);
//     return (result);
// }


// char *clear_line(char *s)
// {
//     int i;
//     int j;
//     int k;
//     char *new_str;
//     char *last_str;

//     i = 0;
//     if (*s == 0)
//         return (NULL);
//     while (s[i] && s[i] != '\n')
//         i++;
//     // printf("[%d] {%s}\n", i, *s);
//     new_str = ft_substr(s, 0, i);
//     // printf("line 1: {%s}\n", new_str);
//     j = i + 1;
//     i = 0;
//     while (s[j] && j <= BUFFER_SIZE)
//         s[i++] = s[j++];
//     s[i] = 0;
//     return (new_str);
// }
