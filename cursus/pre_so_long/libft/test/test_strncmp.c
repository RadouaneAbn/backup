#include "libft.h"
#include <string.h>
#include <stdio.h>

void test_strncmp(const char *s1, const char *s2, size_t n)
{
    // Call original strncmp and ft_strncmp
    int original_result = strncmp(s1, s2, n);
    int ft_result = ft_strncmp(s1, s2, n);

    // Output the results
    printf("Comparing '%s' and '%s' (n = %zu):\n", s1, s2, n);
    printf("Original strncmp : %d\n", original_result);
    printf("ft_strncmp       : %d\n", ft_result);

    // Compare results
    if (original_result != ft_result) {
        printf("❌ FAILURE ❌\n");
    } else {
        printf("✅ SUCCESS ✅\n");
    }

    printf("\n");
}

int main()
{
    // Test cases
    test_strncmp("abcdef", "abcdef", 6);  // Equal strings
    test_strncmp("abcdef", "abcdeg", 6);  // Different at the last character
    test_strncmp("abcdef", "abcde", 6);   // One string shorter
    test_strncmp("abcdef", "abcdef", 4);  // Same string but compare only first 4 characters
    test_strncmp("apple", "banana", 3);   // Completely different strings
    test_strncmp("hello", "HELLO", 5);    // Case sensitivity test

    return 0;
}

