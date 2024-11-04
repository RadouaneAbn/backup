#include <stdio.h>
#include <string.h>
#include <assert.h>

// Example prototype for ft_strnstr
char *ft_strnstr(const char *haystack, const char *needle, size_t len);

void print_result(const char *haystack, const char *needle, size_t len) {
    const char *std_result = strnstr(haystack, needle, len);
    const char *ft_result = ft_strnstr(haystack, needle, len);
    
    printf("Haystack: \"%s\", Needle: \"%s\", Len: %zu\n", haystack, needle ? needle : "NULL", len);
    printf("  strnstr() -> \"%s\"\n", std_result ? std_result : "NULL");
    printf("  ft_strnstr() -> \"%s\"\n", ft_result ? ft_result : "NULL");

    if (std_result == ft_result) {
        printf("✅ SUCCESS ✅\n\n");
    } else {
        printf("❌ FAILURE ❌\n\n");
    }
}

int main() {
    // Test 1: Needle is empty
    char haystack1[] = "Hello, world!";
    char needle1[] = "";
    print_result(haystack1, needle1, 13);

    // Test 2: Needle found within length
    char haystack2[] = "Hello, world!";
    char needle2[] = "world";
    print_result(haystack2, needle2, 13);

    // Test 3: Needle not found within length
    char haystack3[] = "Hello, world!";
    char needle3[] = "world";
    print_result(haystack3, needle3, 5);

    // Test 4: Needle at the end of haystack, found just before length limit
    char haystack4[] = "Find the word end";
    char needle4[] = "end";
    print_result(haystack4, needle4, 17);

    // Test 5: Needle at the end of haystack, but length is too short
    char haystack5[] = "Find the word end";
    char needle5[] = "end";
    print_result(haystack5, needle5, 16);

    // Test 6: Haystack and needle are the same
    char haystack6[] = "Hello!";
    char needle6[] = "Hello!";
    print_result(haystack6, needle6, 6);

    // Test 7: Needle is longer than haystack
    char haystack7[] = "Short";
    char needle7[] = "LongerNeedle";
    print_result(haystack7, needle7, 10);

    // Test 8: Needle found at the beginning of haystack
    char haystack8[] = "Hello, world!";
    char needle8[] = "Hello";
    print_result(haystack8, needle8, 5);

    // Test 9: Partial match but needle not found within limit
    char haystack9[] = "abcdefg";
    char needle9[] = "efg";
    print_result(haystack9, needle9, 5);

    // Test 10: Needle is NULL
    // char haystack10[] = "abcdef";
    // char *needle10 = NULL;
    // print_result(haystack10, needle10, 5);

    // Test 11: Case where haystack is empty
    char haystack11[] = "";
    char needle11[] = "test";
    print_result(haystack11, needle11, 5);

    // Test 12: Needle is found in the middle but only partial match due to length limit
    char haystack12[] = "abcdefgh";
    char needle12[] = "def";
    print_result(haystack12, needle12, 5);

    return 0;
}
