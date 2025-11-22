#include <stdio.h>
#include <string.h>
#include "libft.h"
void print_memchr_result(const void *memchr_res, const void *ft_memchr_res, const char *test_name) {
    printf("%s:\n", test_name);

    // Print the standard memchr result
    if (memchr_res)
        printf("memchr    : Found '%c' at position %ld\n", *(char *)memchr_res, (char *)memchr_res - (char *)memchr_res);
    else
        printf("memchr    : Not found\n");

    // Print the custom ft_memchr result
    if (ft_memchr_res)
        printf("ft_memchr : Found '%c' at position %ld\n", *(char *)ft_memchr_res, (char *)ft_memchr_res - (char *)ft_memchr_res);
    else
        printf("ft_memchr : Not found\n");

    // Compare results
    if (memchr_res == ft_memchr_res) {
        printf("✅ SUCCESS\n\n");
    } else {
        printf("❌ FAILURE\n\n");
    }
}

void run_tests() {
    printf("Running all tests:\n\n");

    // 1. Normal case: Character found in the middle
    char str1[] = "Hello, World!";
    print_memchr_result(memchr(str1, 'W', strlen(str1)), ft_memchr(str1, 'W', strlen(str1)), "Normal case");

    // 2. Character found at the beginning
    char str2[] = "Hello, World!";
    print_memchr_result(memchr(str2, 'H', strlen(str2)), ft_memchr(str2, 'H', strlen(str2)), "Character at the beginning");

    // 3. Character found at the end
    char str3[] = "Hello, World!";
    print_memchr_result(memchr(str3, '!', strlen(str3)), ft_memchr(str3, '!', strlen(str3)), "Character at the end");

    // 4. Character not found
    char str4[] = "Hello, World!";
    print_memchr_result(memchr(str4, 'X', strlen(str4)), ft_memchr(str4, 'X', strlen(str4)), "Character not found");

    // 5. Empty string
    char str5[] = "";
    print_memchr_result(memchr(str5, 'H', strlen(str5)), ft_memchr(str5, 'H', strlen(str5)), "Empty string");

    // 6. Multiple occurrences of character (returns the first occurrence)
    char str6[] = "This is a test string with multiple 't's";
    print_memchr_result(memchr(str6, 't', strlen(str6)), ft_memchr(str6, 't', strlen(str6)), "Multiple occurrences of character");

    // 7. Non-printable character (newline \n)
    char str7[] = "Line1\nLine2";
    print_memchr_result(memchr(str7, '\n', strlen(str7)), ft_memchr(str7, '\n', strlen(str7)), "Non-printable character (newline)");

    // 8. Boundary condition: size n smaller than string length, character found
    char str8[] = "Boundary test";
    print_memchr_result(memchr(str8, 't', 8), ft_memchr(str8, 't', 8), "Boundary condition (found within limit)");

    // 9. Boundary condition: size n smaller than string length, character not found
    print_memchr_result(memchr(str8, 's', 5), ft_memchr(str8, 's', 5), "Boundary condition (not found within limit)");

    // 10. Test with null byte (\0)
    char str9[] = "Test\0String";
    print_memchr_result(memchr(str9, '\0', 11), ft_memchr(str9, '\0', 11), "Null byte in the string");

    // 11. Search for character after a null byte
    print_memchr_result(memchr(str9, 'S', 11), ft_memchr(str9, 'S', 11), "Search after null byte");

    // 12. Search for a null byte when it's not present
    char str10[] = "This is a string.";
    print_memchr_result(memchr(str10, '\0', strlen(str10)), ft_memchr(str10, '\0', strlen(str10)), "Search for null byte (not present)");

    // 13. Zero size n (should return NULL)
    char str11[] = "Non-empty string";
    print_memchr_result(memchr(str11, 'N', 0), ft_memchr(str11, 'N', 0), "Zero size n");

    // 14. Search for character in a large buffer (stress test)
    char large_str[1000];
    memset(large_str, 'A', 999);
    large_str[999] = '\0';
    print_memchr_result(memchr(large_str, 'B', 1000), ft_memchr(large_str, 'B', 1000), "Large buffer (character not present)");

    // 15. Search for character in a large buffer (found)
    large_str[500] = 'B';
    print_memchr_result(memchr(large_str, 'B', 1000), ft_memchr(large_str, 'B', 1000), "Large buffer (character found)");

    // 16. Search in the middle of a string
    char str12[] = "abcdefghij";
    print_memchr_result(memchr(str12 + 5, 'h', 5), ft_memchr(str12 + 5, 'h', 5), "Search in the middle of the string");
}


int main() {
    // Run all tests
    run_tests();
    return 0;
}
