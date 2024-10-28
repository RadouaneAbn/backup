#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototype for ft_atoi
int ft_atoi(const char *str);

void test_atoi(const char *str) {
    int expected = atoi(str);
    int result = ft_atoi(str);

    if (result == expected) {
        printf("PASS: \"%s\" -> Got: %d\n", str, result);
    } else {
        printf("FAIL: \"%s\" -> Got: %d, Expected: %d\n", str, result, expected);
    }
}

int main() {
    // Test 1: Basic positive number
    test_atoi("42");

    // Test 2: Basic negative number
    test_atoi("-42");

    // Test 3: Zero
    test_atoi("0");

    // Test 4: Positive number with whitespace
    test_atoi("    123");

    // Test 5: Negative number with whitespace
    test_atoi("   -123");

    // Test 6: Number with leading zeroes
    test_atoi("0000042");

    // Test 7: Large positive number
    test_atoi("2147483647");  // INT_MAX

    // Test 8: Large negative number
    test_atoi("-2147483648"); // INT_MIN

    // Test 9: Number with trailing characters
    test_atoi("42abc");

    // Test 10: Only whitespace
    test_atoi("   ");

    // Test 11: Empty string
    test_atoi("");

    // Test 12: Just a minus sign
    test_atoi("-");

    // Test 13: Plus sign followed by a number
    test_atoi("+123");

    // Test 14: Non-numeric string
    test_atoi("abc123");

    // Test 15: Plus and minus together
    test_atoi("+-123");

    // Test 16: Whitespace and plus sign before number
    test_atoi("   +456");

    // Test 17: Multiple whitespaces around a number
    test_atoi(" \t\n 789");

    return 0;
}
