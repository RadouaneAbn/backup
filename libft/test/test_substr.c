#include <stdio.h>
#include <string.h>
#include <assert.h>

// Example prototype for ft_substr
char *ft_substr(const char *s, unsigned int start, size_t len);

int main() {
    // Test 1: Normal substring extraction
    char str1[] = "Hello, world!";
    char *sub1 = ft_substr(str1, 7, 5);  // Extract "world"
    printf("Test 1: Extract 'world', result: %s\n", sub1);
    assert(strcmp(sub1, "world") == 0);

    // Test 2: Start index greater than the string length
    char str2[] = "Hello!";
    char *sub2 = ft_substr(str2, 10, 5);  // Start is beyond the string, should return an empty string
    printf("Test 2: Start index beyond string length, result: %s\n", sub2);
    assert(strcmp(sub2, "") == 0);

    // Test 3: Length exceeds remaining string
    char str3[] = "abcdef";
    char *sub3 = ft_substr(str3, 2, 10);  // Extract from index 2 but len exceeds string end ("cdef")
    assert(strcmp(sub3, "cdef") == 0);
    printf("Test 3: Length exceeds remaining string, result: %s\n", sub3);

    // Test 4: Start is 0 (extract from the beginning)
    char str4[] = "Extract this!";
    char *sub4 = ft_substr(str4, 0, 7);  // Extract "Extract"
    printf("Test 4: Extract from the start, result: %s\n", sub4);
    assert(strcmp(sub4, "Extract") == 0);

    // Test 5: Length is 0 (should return an empty string)
    char str5[] = "Nothing here";
    char *sub5 = ft_substr(str5, 3, 0);  // Length is 0, should return ""
    printf("Test 5: Length is 0, result: %s\n", sub5);
    assert(strcmp(sub5, "") == 0);

    // Test 6: Start and length cover the entire string
    char str6[] = "Full string";
    char *sub6 = ft_substr(str6, 0, strlen(str6));  // Extract the entire string
    printf("Test 6: Extract full string, result: %s\n", sub6);
    assert(strcmp(sub6, "Full string") == 0);

    // Test 7: String is empty
    char str7[] = "";
    char *sub7 = ft_substr(str7, 0, 5);  // Empty string input, should return ""
    printf("Test 7: Empty string, result: %s\n", sub7);
    assert(strcmp(sub7, "") == 0);

    printf("All tests passed!\n");
    return 0;
}

