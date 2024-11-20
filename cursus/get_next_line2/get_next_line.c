#include "get_next_line.h"

size_t ft_strlen(char *s)
{
    size_t i;

    if (s == NULL)
        return (0);
    i = 0;
    while (s[i])
        i++;
    return (i);
}

char *ft_strdup(char *s)
{
    size_t i;
    size_t slen;
    char *new;

    if (s == NULL)
        return (NULL);
    i = 0;
    slen = ft_strlen(s);
    new = malloc(slen + 1);
    if (new == NULL)
    return (NULL);
    while (s[i])
    {
        new[i] = s[i];
        i++;
    }
    new[i] = '\0';
    return (new);
}

void appendto_line(char **line, t_buf *buffer)
{
    int i = 0;
    size_t line_len = ft_strlen(*line);
    char *new_line;

    new_line = malloc((line_len + buffer->idx + 1) * sizeof(char));
    if (new_line == NULL)
        return ;
    if (*line)
    {
        while ((*line)[i])
        {
            new_line[i] = (*line)[i];
            i++;
        }
    }
    while (buffer->str[i])
    {
        new_line[i] = buffer->str[i];
        i++;
    }
    new_line[i] = '\0';
    if (*line)
        free(*line);
    *line = new_line;
}

int appendto_buffer(char *tmp, t_buf *buffer, char **line)
{
    int i;

    i = 0;
    while (tmp[i] && tmp[i] != '\n' && buffer->idx < 2047)
        buffer->str[(buffer->idx)++] = tmp[i++];
    buffer->str[buffer->idx] = '\0';
    if (tmp[i] && buffer->idx == 2047)
    {
        appendto_line(line, buffer);
        buffer->idx = 0;
        appendto_buffer(tmp + i, buffer, line);
    }
}

int nl_found(char *s)
{
    int i = 0;

    while (s[i] && s[i] != '\n')
        i++;
    return (s[i] == '\n');
}

char *last_clean(char *s, void (*f)(void *))
{
    int i;
    int j;
    size_t slen;
    char *last;

    printf(">> cleaning line <<\nline:\n>>>\n%s\n<<<\n", s);
    i = 0;
    while (s[i] && s[i] != '\n')
        i++;
    printf("newline found in %d ascii=[%d]\n", i, s[i]);
    if (s[i] == '\0' || s[i + 1] == '\0')
    {
        if (f && s)
            f(s);
        return (NULL);
    }
    j = i + 1;
    i = 0;
    printf("first char after newline: [%c]\n", s[j]);
    // slen = ft_strlen(s + j) + 1;
    printf("size malloced: %zu\n", slen);
    // last = malloc(slen * sizeof(char));
    // if (last == NULL)
    //     return (NULL);
    // while (s[j])
    //     last[i++] = s[j++];
    // last[i] = '\0';
    last = ft_strdup(s + j);
    return (last);
}

char *get_next_line(int fd)
{
    static char *last;
    char b_tmp[BUFFER_SIZE + 1];
    t_buf buffer;
    ssize_t size;
    char *line;

    buffer.idx = 0;
    line = NULL;
    if (last == NULL)
    {
        while ((size = read(fd, b_tmp, BUFFER_SIZE)) > 0)
        {
            b_tmp[size] = '\0';
            appendto_buffer(b_tmp, &buffer, &line);
            if (nl_found(b_tmp))
                break;
        }
        appendto_line(&line, &buffer);
        printf("> result: %s\n", line);
        last = last_clean(b_tmp, NULL);
    }
    return (line);
}
