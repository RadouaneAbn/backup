#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *ft_itoa(int n);

void test_itoa(int input, const char *expected) {
    char *result = ft_itoa(input);
    if (strcmp(result, expected) != 0) {
        printf("Test failed for input %d\n", input);
        printf("Got:      %s\n", result);
        printf("Expected: %s\n", expected);
    } else {
        printf("Test passed for input %d\n", input);
    }
    free(result);
}

int main() {
    test_itoa(0, "0");
    test_itoa(5, "5");
    test_itoa(-3, "-3");
    test_itoa(1234, "1234");
    test_itoa(-9876, "-9876");
    test_itoa(2147483647, "2147483647");
    test_itoa(-2147483648, "-2147483648");
    test_itoa(105, "105");
    test_itoa(-2048, "-2048");
    test_itoa(-1, "-1");
    test_itoa(1234567890, "1234567890");
    test_itoa(-1234567890, "-1234567890");
    test_itoa(-10, "-10");
    test_itoa(99, "99");
    test_itoa(10, "10");
    test_itoa(0, "0");
    test_itoa(1000, "1000");
    test_itoa(-1000, "-1000");
    test_itoa(1, "1");
    test_itoa(-1, "-1");
    for (int i = -1; i >= -9; i--) {
        char expected[3];
        sprintf(expected, "%d", i);
        test_itoa(i, expected);
    }

    for (int i = 1; i <= 9; i++) {
        char expected[2];
        sprintf(expected, "%d", i);
        test_itoa(i, expected);
    }

    printf("All tests completed!\n");
    return 0;
}

