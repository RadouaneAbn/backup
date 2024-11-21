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

void appendto_line(char **line, char *buffer)
{
    int i = 0;
    size_t line_len = ft_strlen(*line);
    size_t buffer_len = ft_strlen(buffer);
    char *new_line;

    new_line = malloc((line_len + buffer_len + 1) * sizeof(char));
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
    while (buffer[i])
    {
        new_line[i] = buffer[i];
        i++;
    }
    new_line[i] = '\0';
    if (*line)
        free(*line);
    *line = new_line;
}

void appendto_buffer(char *tmp, t_buf *buffer, char **line)
{
    int i;

    i = 0;
    while (tmp[i] && buffer->idx < 2047)
    {
        buffer->str[(buffer->idx)++] = tmp[i];
        if (tmp[i++] == '\n')
            break;
    }
    buffer->str[buffer->idx] = '\0';
    if (tmp[i] && buffer->idx == 2047)
    {
        appendto_line(line, buffer->str);
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
    char *last;

    if (DM) printf("cleaning line...\n>>>\n%s\n>>>\n<<<\n", s);
    i = 0;
    while (s[i] && s[i] != '\n')
        i++;
    if (DM) printf("newline found in %d ascii=[%d]\n", i, s[i]);
    if (s[i] == '\0' || s[i + 1] == '\0')
    {
        if (f && s)
            f(s);
        return (NULL);
    }
    j = i + 1;
    last = ft_strdup(s + j);
    if (last == NULL)
        return (NULL);
    if (DM) printf("%s\n<<<\n\n", last);
    return (last);
}

char *get_next_line(int fd)
{
    static char *last;
    char b_tmp[BUFFER_SIZE + 1];
    t_buf buffer;
    ssize_t size;
    char *line;

    if (DM) printf("read from: %d\n", fd);

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, b_tmp, 0) == -1)
        return (NULL);
    buffer.idx = 0;
    line = NULL;
    b_tmp[0] = 0;
    if (DM) printf("last line: %s\n", last);
    if (last)
    {
        if (nl_found(last))
        {
            if (DM) printf("last -> nl\n");
            // appendto_line(&line, last);
            appendto_buffer(last, &buffer, &line);
            appendto_line(&line, buffer.str);
            last = last_clean(last, free);
        }
        else
        {
            if (DM) printf("last -> nonl\n");
            appendto_buffer(last, &buffer, &line);
            free(last);
            last = NULL;
        }
    }
    if (last == NULL)
    {
        while ((size = read(fd, b_tmp, BUFFER_SIZE)) > 0)
        {
            if (DM) printf("size read: %ld\n", size);
            b_tmp[size] = '\0';
            if (DM) printf("read: %s\n", b_tmp);
            appendto_buffer(b_tmp, &buffer, &line);
            if (nl_found(b_tmp))
                break;
        }
        if (DM) printf("size read: %ld\n", size);
        if (DM) printf("buf idx: %zu\n", buffer.idx);
        if (size <= 0 && buffer.idx == 0)
            return (NULL);
        appendto_line(&line, buffer.str);
        if (DM) printf("tmp: %s\n", b_tmp);
        last = last_clean(b_tmp, NULL);
    }
    return (line);
}
