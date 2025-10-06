#include "libft.h"
#include <string.h>
#include <stdio.h>


void test_strdup(char *s)
{
    char *f = ft_strdup(s);
    char *o = strdup(s);

    printf("original: '%s'\n", s);
    printf("strdup  : '%s'\n", o);
    printf("original: '%s'\n", f);
    if (strcmp(o, f) == 0) {
        printf("SUCCESS\n\n");
    } else {
        printf("FAILED !!!\n\n");
    }
    free(f);
    free(o);
}

int main () {
    test_strdup("");
    test_strdup("Hola");
    test_strdup(" Hello world");
    test_strdup("123456   123456");
    test_strdup("test new line \n result");
    return (0);
}