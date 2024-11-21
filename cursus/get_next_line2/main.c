#include "get_next_line.h"

void multiple_line_no_nl()
{
    printf("#####################################\nmultiple_line_no_nl:\n");
    int i = 1;
    int fd = open("files/multiple_line_no_nl", O_RDONLY);
    char *line = get_next_line(fd);
    printf("-%d): %s", i++, line);
    if (DM) printf("============================================\n");
    line = get_next_line(fd);
    printf("-%d): %s", i++, line);
    if (DM) printf("============================================\n");
    line = get_next_line(fd);
    printf("-%d): %s", i++, line);
    if (DM) printf("============================================\n");
    line = get_next_line(fd);
    printf("-%d): %s", i++, line);
    if (DM) printf("============================================\n");
    line = get_next_line(fd);
    printf("-%d): %s", i++, line);
    if (DM) printf("============================================\n");
    line = get_next_line(fd);
    printf("-%d): %s", i++, line);
}

void multiple_line_with_nl()
{
    printf("#####################################\nmultiple_line_with_nl:\n");
    int i = 1;
    int fd = open("files/multiple_line_with_nl", O_RDONLY);
    char *line = get_next_line(fd);
    printf("-%d): %s", i++, line);
    if (DM) printf("============================================\n");
    line = get_next_line(fd);
    printf("-%d): %s", i++, line);
    if (DM) printf("============================================\n");
    line = get_next_line(fd);
    printf("-%d): %s", i++, line);
    if (DM) printf("============================================\n");
    line = get_next_line(fd);
    printf("-%d): %s", i++, line);
    if (DM) printf("============================================\n");
    line = get_next_line(fd);
    printf("-%d): %s", i++, line);
    if (DM) printf("============================================\n");
    line = get_next_line(fd);
    printf("-%d): %s", i++, line);
}

void _41_no_nl()
{
    printf("#####################################\n41_no_nl:\n");
    int i = 1;
    int fd = open("files/41_no_nl", O_RDONLY);
    char *line;
    
    line = get_next_line(fd);
    printf("-%d): %s", i++, line);
    if (DM) printf("============================================\n");
    line = get_next_line(fd);
    printf("-%d): %s", i++, line);
}

void _41_with_nl()
{
    printf("#####################################\n41_with_nl:\n");
    int i = 1;
    int fd = open("files/41_with_nl", O_RDONLY);
    char *line;
    
    line = get_next_line(fd);
    printf("-%d): %s", i++, line);
    if (DM) printf("============================================\n");
    line = get_next_line(fd);
    printf("-%d): %s", i++, line);
    if (DM) printf("============================================\n");
    line = get_next_line(fd);
    printf("-%d): %s", i++, line);
}


void _42_no_nl()
{
    printf("#####################################\n42_no_nl:\n");
    int i = 1;
    int fd = open("files/42_no_nl", O_RDONLY);
    char *line;
    
    line = get_next_line(fd);
    printf("-%d): %s", i++, line);
    if (DM) printf("============================================\n");
    line = get_next_line(fd);
    printf("-%d): %s", i++, line);
}

void _42_with_nl()
{
    printf("#####################################\n42_with_nl:\n");
    int i = 1;
    int fd = open("files/42_with_nl", O_RDONLY);
    char *line;
    
    line = get_next_line(fd);
    printf("-%d): %s", i++, line);
    if (DM) printf("============================================\n");
    line = get_next_line(fd);
    printf("-%d): %s", i++, line);
    if (DM) printf("============================================\n");
    line = get_next_line(fd);
    printf("-%d): %s", i++, line);
}


void _43_no_nl()
{
    printf("#####################################\n43_no_nl:\n");
    int i = 1;
    int fd = open("files/43_no_nl", O_RDONLY);
    char *line;
    
    line = get_next_line(fd);
    printf("-%d): %s", i++, line);
    if (DM) printf("============================================\n");
    line = get_next_line(fd);
    printf("-%d): %s", i++, line);
}

void _43_with_nl()
{
    printf("#####################################\n43_with_nl:\n");
    int i = 1;
    int fd = open("files/43_with_nl", O_RDONLY);
    char *line;
    
    line = get_next_line(fd);
    printf("-%d): %s", i++, line);
    if (DM) printf("============================================\n");
    free(line);
    line = get_next_line(fd);
    printf("-%d): %s", i++, line);
    printf("============================================\n");
    free(line);
    line = get_next_line(fd);
    printf("-%d): %s", i++, line);
}

void multiple_nl_txt()
{
    printf("#####################################\nmultiple_nl.txt:\n");
    int i = 1;
    int fd = open("files/multiple_nl.txt", O_RDONLY);
    char *line;
    
    line = get_next_line(fd);
    printf("-%d): %s", i++, line);
    free(line);
    if (DM) printf("============================================\n");

    line = get_next_line(fd);
    printf("-%d): %s", i++, line);
    free(line);
    if (DM) printf("============================================\n");

    line = get_next_line(fd);
    printf("-%d): %s", i++, line);
    free(line);
    if (DM) printf("============================================\n");

    line = get_next_line(fd);
    printf("-%d): %s", i++, line);
    free(line);
    if (DM) printf("============================================\n");

    line = get_next_line(fd);
    printf("-%d): %s", i++, line);
    free(line);
    if (DM) printf("============================================\n");

    line = get_next_line(fd);
    printf("-%d): %s", i++, line);
    free(line);
    if (DM) printf("============================================\n");

    line = get_next_line(fd);
    printf("-%d): %s", i++, line);
    free(line);
    if (DM) printf("============================================\n");
}

int main() {
    // multiple_line_no_nl();
    // multiple_line_with_nl();
    // _41_no_nl();
    // _41_with_nl();
    // _42_no_nl();
    // _42_with_nl();
    // _43_no_nl();
    _43_with_nl();
    // multiple_nl_txt();
    return (0);
}