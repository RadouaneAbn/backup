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
    if (s[i] == '\0')
    {
        s[0] = '\0';
        return ;
    }
    j = i + 1;
    i = 0;
    while (s[j])
        s[i++] = s[j++];
    s[i] = '\0';
}

char *get_next_line(int fd)
{
    static char last[BUFFER_SIZE + 1];
    t_buf b;
    char *line;
    ssize_t size_read;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    b.idx = 0;
    b.buffer[0] = '\0';
    line = NULL;
    if (last[0])
    {
        ft_appendto_buffer(last, &b, &line);
        ft_append_str(&line, b.buffer);
        if (newline_found(last)) // If leftover contains a newline, stop
        {
            clear_line(last);
            return (line);
        }
        clear_line(last);
    }
    // if (read(fd, last, 0) == -1)
    //     return (NULL);
    while ((size_read = read(fd, last, BUFFER_SIZE)) > 0)
    {
        last[size_read] = '\0';
        ft_appendto_buffer(last, &b, &line);
        if (newline_found(last))
            break ;
    }
    if (size_read == -1)
        return (NULL);
    ft_appendto_buffer(last, &b, &line);
    ft_append_str(&line, b.buffer);
    clear_line(last);
    return (line);
}

// char *get_next_line(int fd)
// {
//     static char last[BUFFER_SIZE + 1];
//     t_buf b;
//     char *line;
//     ssize_t size_read;

//     if (fd < 0)
//         return (NULL);
//     b.idx = 0;
//     b.buffer[0] = 0;
//     line = NULL;
//     while (!newline_found(last))
//     {
//         ft_appendto_buffer(last, &b, &line);
//         size_read = read(fd, last, BUFFER_SIZE);
//         if (size_read < 0)
//             break;
//         if (size_read == 0)
//             break;
//     }
//     // printf("[%ld]: {%s}\n", size_read, last);
//     if (last[0])
//     {
//         ft_appendto_buffer(last, &b, &line);
//         ft_append_str(&line, b.buffer);
//         clear_line(last);
//     }
//     return (line);
// }

// char *get_next_line(int fd)
// {
//     static char last[BUFFER_SIZE + 1];
//     t_buf b;
//     char *line;
//     ssize_t size_read;

//     if (fd < 0)
//         return (NULL);
//     b.idx = 0;
//     b.buffer[0] = 0;
//     line = NULL;
//     while (!newline_found(last))
//     {
//         ft_appendto_buffer(last, &b, &line);
//         // printf("BUFFER: {%s}\n", b.buffer);
//         size_read = read(fd, last, BUFFER_SIZE);
//         if (size_read <= 0) { // End of file or error
//             if (b.buffer[0] && size_read == 0) {
//                 ft_append_str(&line, b.buffer); // Append final part of the line
//                 return (line);
//             }
//             // free(line);
//             return (NULL);
//         }
//         last[size_read] = '\0';
//     }
//     // printf("[%ld]: {%s}\n", size_read, last);

//     ft_appendto_buffer(last, &b, &line);
//     ft_append_str(&line, b.buffer);
//     clear_line(last);
//     return (line);
// }
