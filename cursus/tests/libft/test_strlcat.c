#include <stdio.h>
#include <string.h> // for the original strlcat
#include "libft.h" // for your ft_strlcat

#define BUFFER_SIZE 100

void test_strlcat(char *dst, const char *src, size_t dstsize, const char *expected, const char *test_case_name) {
    char original_dst[BUFFER_SIZE];
    char ft_dst[BUFFER_SIZE];

	printf("IGNORE %s\n", expected);
    // Initialize the buffers with the same values
    strncpy(original_dst, dst, BUFFER_SIZE);
    strncpy(ft_dst, dst, BUFFER_SIZE);

    // Apply strlcat and ft_strlcat
    size_t original_ret = strlcat(original_dst, src, dstsize);
    size_t ft_ret = ft_strlcat(ft_dst, src, dstsize);

    // Compare results
    printf("Test case: %s\n", test_case_name);
    printf("Original: strlcat returned %zu, dst: '%s'\n", original_ret, original_dst);
    printf("Custom  : ft_strlcat returned %zu, dst: '%s'\n", ft_ret, ft_dst);

    if (original_ret == ft_ret && strcmp(original_dst, ft_dst) == 0) {
        printf("✅ SUCCESS\n\n");
    } else {
        printf("❌ FAILURE\n\n");
    }
}

int main() {
    // Test 1: Simple concatenation
    test_strlcat("Hello, ", "World!", 100, "Hello, World!", "Simple concatenation");

    // Test 2: Destination buffer is full
    test_strlcat("Hello, ", "World!", 7, "Hello,", "Destination buffer exactly full");

    // Test 3: Destination buffer size is too small
    test_strlcat("Hello, ", "World!", 5, "Hello", "Destination buffer too small");

    // Test 4: Empty source string
    test_strlcat("Hello, ", "", 100, "Hello, ", "Empty source string");

    // Test 5: Empty destination string
    test_strlcat("", "World!", 100, "World!", "Empty destination string");

    // Test 6: Exact fit
    test_strlcat("Hello", "World", 11, "HelloWorld", "Exact fit in the buffer");

    // Test 7: Large buffer, very small concatenation
    test_strlcat("Hello", "World", 100, "HelloWorld", "Large buffer, small concatenation");

    // Test 8: Buffer size is 0
    test_strlcat("Hello", "World", 0, "Hello", "Buffer size is 0");

    // Test 9: Buffer size 1, should only write null terminator
    test_strlcat("Hello", "World", 1, "Hello", "Buffer size 1, no concatenation");

    // Test 10: src size larger than buffer, truncation
    test_strlcat("A", "12345678901234567890", 10, "A123456789", "Source string larger than buffer");

    // Test 11: dst and src overlap (undefined behavior but interesting to test)
    char overlap_dst[20] = "Hello";
    test_strlcat(overlap_dst, overlap_dst + 2, 10, "Hellollo", "Overlapping strings (undefined behavior)");

    // Test 12: dst is empty and small
    test_strlcat("", "Testing", 5, "Test", "Empty dst and small size");

    // Test 13: Both dst and src are empty
    test_strlcat("", "", 5, "", "Both dst and src are empty");

    return 0;
}
