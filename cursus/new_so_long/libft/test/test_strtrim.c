#include "libft.h"
#include <stdio.h>
#include <string.h>

void test_strtrim(char *s, char *set, char *ex) {
    char *ns = ft_strtrim(s, set);
    printf("str       : %s\n", s);
    printf("The set   : %s\n", set);
    printf("The result: %s\n", ns);

    if (ex == NULL)
    {
        if (ns == NULL)
            printf("✅ SUCCESS ✅\n\n");
        else{
            printf("❌ FAILURE ❌\n");
            printf("--> Expected: %s\n\n", "(null)");
        }
        return ;
    }
    if (strcmp(ns, ex) != 0) {
        printf("❌ FAILURE ❌\n");
        printf("--> Expected: %s\n\n", ex);
    } else {
        printf("✅ SUCCESS ✅\n\n");
    }
    if (ns)
        free(ns);
}

int main () {
    test_strtrim("Test to remove something", "tv", "Test to remove something");
    test_strtrim("Test to remove something", "", "Test to remove something");
    test_strtrim("", "red", "");
    test_strtrim("Test to remove something", "Tegns", "t to remove somethi");
    test_strtrim("He plays a lot!", " tlo !", "He plays a");
    test_strtrim("He plays a lot!", NULL, "He plays a lot!");
    test_strtrim(NULL, "red", NULL);
    test_strtrim(NULL, NULL, NULL);
    return (0);
}