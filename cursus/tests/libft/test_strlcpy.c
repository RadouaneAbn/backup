#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

// Example prototype for ft_strlcpy
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);

int main() {
    char dest[100];

    // Test 1: Basic copy
    strcpy(dest, "Initial");
    assert(strlcpy(dest, "Hello", sizeof(dest)) == ft_strlcpy(dest, "Hello", sizeof(dest)));
    assert(strcmp(dest, "Hello") == 0);

    // Test 2: src string is longer than dstsize (should truncate src)
    strcpy(dest, "Initial");
    assert(strlcpy(dest, "A longer string", 5) == ft_strlcpy(dest, "A longer string", 5));
    assert(strcmp(dest, "A lo") == 0);

    // Test 3: dstsize is 0 (should not copy anything, but return length of src)
    strcpy(dest, "Initial");
    assert(strlcpy(dest, "NewString", 0) == ft_strlcpy(dest, "NewString", 0));
    assert(strcmp(dest, "Initial") == 0);  // dest remains unchanged

    // Test 4: src is empty string (should make dest an empty string)
    strcpy(dest, "Initial");
    assert(strlcpy(dest, "", sizeof(dest)) == ft_strlcpy(dest, "", sizeof(dest)));
    assert(strcmp(dest, "") == 0);

    // Test 5: dstsize is 1 (only enough space for the null terminator)
    strcpy(dest, "Initial");
    assert(strlcpy(dest, "Test", 1) == ft_strlcpy(dest, "Test", 1));
    assert(strcmp(dest, "") == 0);  // Only null-terminator should be copied

    // Test 6: dstsize is smaller than src length, should truncate src to fit within dstsize
    strcpy(dest, "Initial");
    assert(strlcpy(dest, "123456789", 4) == ft_strlcpy(dest, "123456789", 4));
    assert(strcmp(dest, "123") == 0);  // "123" fits within 4 bytes, including the null terminator

    // Test 7: Very large src and small dstsize (just to test the limit cases)
    char long_src[1000];
    memset(long_src, 'A', 999);
    long_src[999] = '\0';  // null-terminate the long source string
    assert(strlcpy(dest, long_src, sizeof(dest)) == ft_strlcpy(dest, long_src, sizeof(dest)));
    assert(strlen(dest) == 99);  // only 99 characters + null terminator should fit

    printf("All tests passed!\n");
    return 0;
}

