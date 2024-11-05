#include "libft.h"
#include <string.h>
#include <stdio.h>

void  test_strjoin(char *s1, char *s2,  char *expected)
{
    char *s =  ft_strjoin(s1, s2);
    printf("joining: <[%s]> + <[%s]>\n", s1, s2);
    printf("result: <[%s]>\n",s);
    if (strcmp(s, expected) != 0) {
        printf("❌ FAILURE ❌\n");
    } else {
        printf("✅ SUCCESS ✅\n");
    }
    free(s);
}


int main()  {
    test_strjoin("hello ",  "world", "hello world");
    test_strjoin("hello ",  " world  ", "hello  world  ");
    test_strjoin("hello ",  "", "hello ");
    test_strjoin("",  "world", "world");
    test_strjoin("",  "",  "");
    return (0);
}