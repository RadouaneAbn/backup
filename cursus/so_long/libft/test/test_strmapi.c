#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *ft_strmapi(char const *s, char (*f)(unsigned int, char));

char example_function(unsigned int i, char c) {
    if (i % 2 == 0 && c >= 'a' && c <= 'z') {
        return c - 32;
    }
    return c;
}

void test_strmapi(const char *input, char (*func)(unsigned int, char), const char *expected) {
    char *result = ft_strmapi(input, func);
    if ((result == NULL && expected != NULL) || (result != NULL && strcmp(result, expected) != 0)) {
        printf("Test failed for input \"%s\"\n", input);
        printf("Got:      %s\n", result ? result : "NULL");
        printf("Expected: %s\n", expected ? expected : "NULL");
    } else {
        printf("Test passed for input \"%s\"\n", input);
    }
    free(result);
}

char add_index(unsigned int i, char c) {
    return c + i;
}

int main() {
    test_strmapi("abcdefg", example_function, "AbCdEfG");

    test_strmapi("hijklmnop", example_function, "HiJkLmNoP");

    test_strmapi("", example_function, "");

    test_strmapi(NULL, example_function, NULL);

    test_strmapi("abcd", add_index, "aceg");

    test_strmapi("TestString", add_index, "TfuwWyxpvp");

    test_strmapi("a1b2c3!", example_function, "A1B2C3!");

    test_strmapi("a b c d e", example_function, "A B C D E");

    test_strmapi("!@#$%^", add_index, "!A%')c");

    test_strmapi("HELLO WORLD", example_function, "HELLO WORLD");

    test_strmapi("12345", example_function, "12345");

    test_strmapi("?!&^$", add_index, "?\"(a(");

    test_strmapi("x", example_function, "X");
    test_strmapi("z", add_index, "z");

    printf("All tests completed!\n");
    return 0;
}

