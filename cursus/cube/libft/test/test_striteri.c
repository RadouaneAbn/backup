#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strdup(const char *s1);

void example_function(unsigned int i, char *s) {
    if (i % 2 == 0 && *s >= 'a' && *s <= 'z') {
        *s -= 32;
    }
}

void test_striteri(const char *input, void (*func)(unsigned int, char*), const char *expected) {
    char *s;
    if (input == NULL)
        s = NULL;
    else
        s = ft_strdup(input);
    ft_striteri(s, func);
    if ((s == NULL && expected != NULL) || (s != NULL && strcmp(s, expected) != 0)) {
        printf("Test failed for input \"%s\"\n", input);
        printf("Got:      %s\n", s ? s : "NULL");
        printf("Expected: %s\n", expected ? expected : "NULL");
    } else {
        printf("Test passed for input \"%s\"\n", input);
    }
    if (s != NULL)
        free(s);
}

void add_index(unsigned int i, char *s) {
    *s += i;
}

int main() {
    test_striteri("abcdefg", example_function, "AbCdEfG");

    test_striteri("hijklmnop", example_function, "HiJkLmNoP");

    test_striteri("", example_function, "");

    test_striteri(NULL, example_function, NULL);

    test_striteri("abcd", add_index, "aceg");

    test_striteri("TestString", add_index, "TfuwWyxpvp");

    test_striteri("a1b2c3!", example_function, "A1B2C3!");

    test_striteri("a b c d e", example_function, "A B C D E");

    test_striteri("!@#$%^", add_index, "!A%')c");

    test_striteri("HELLO WORLD", example_function, "HELLO WORLD");

    test_striteri("12345", example_function, "12345");

    test_striteri("?!&^$", add_index, "?\"(a(");

    test_striteri("x", example_function, "X");
    test_striteri("z", add_index, "z");

    printf("All tests completed!\n");
    return 0;
}

