#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

// Example prototype for ft_split
char **ft_split(const char *s, char c);

// Helper function to free the array returned by ft_split
void free_split(char **split) {
    for (int i = 0; split[i] != NULL; i++) {
        free(split[i]);
    }
    free(split);
}

// Helper function to print the split array
void print_split(char **split) {
    int i = 0;
    while (split[i] != NULL) {
        printf("'%s' ", split[i]);
        i++;
    }
    printf("\n");
}

int main() {
    // Test 1: Basic split
    char str1[] = "Hello world split this";
    char **split1 = ft_split(str1, ' ');
    char *expected1[] = {"Hello", "world", "split", "this", NULL};
    for (int i = 0; expected1[i] != NULL; i++) {
        assert(strcmp(split1[i], expected1[i]) == 0);
    }
    assert(split1[4] == NULL);  // Check NULL termination
    printf("Test 1 passed: ");
    print_split(split1);
    free_split(split1);

    // Test 2: Consecutive delimiters
    char str2[] = "Hello,,world";
    char **split2 = ft_split(str2, ',');
    char *expected2[] = {"Hello", "world", NULL};
    for (int i = 0; expected2[i] != NULL; i++) {
        assert(strcmp(split2[i], expected2[i]) == 0);
    }
    assert(split2[2] == NULL);
    printf("Test 2 passed: ");
    print_split(split2);
    free_split(split2);

    // Test 3: Delimiter at start and end
    char str3[] = ",start and end,";
    char **split3 = ft_split(str3, ',');
    char *expected3[] = {"start and end", NULL};
    for (int i = 0; expected3[i] != NULL; i++) {
        assert(strcmp(split3[i], expected3[i]) == 0);
    }
    assert(split3[1] == NULL);
    printf("Test 3 passed: ");
    print_split(split3);
    free_split(split3);

    // Test 4: No delimiter present
    char str4[] = "nodivider";
    char **split4 = ft_split(str4, ',');
    char *expected4[] = {"nodivider", NULL};
    assert(strcmp(split4[0], expected4[0]) == 0);
    assert(split4[1] == NULL);
    printf("Test 4 passed: ");
    print_split(split4);
    free_split(split4);

    // Test 5: Entire string is delimiters
    char str5[] = ",,,,";
    char **split5 = ft_split(str5, ',');
    assert(split5[0] == NULL);  // Should return an array with just NULL
    printf("Test 5 passed: No elements as expected\n");
    free_split(split5);

    // Test 6: Empty string input
    char str6[] = "";
    char **split6 = ft_split(str6, ',');
    assert(split6[0] == NULL);  // Should return an array with just NULL
    printf("Test 6 passed: No elements as expected\n");
    free_split(split6);

    // Test 7: Multiple words separated by space
    char str7[] = "split me into words";
    char **split7 = ft_split(str7, ' ');
    char *expected7[] = {"split", "me", "into", "words", NULL};
    for (int i = 0; expected7[i] != NULL; i++) {
        assert(strcmp(split7[i], expected7[i]) == 0);
    }
    assert(split7[4] == NULL);
    printf("Test 7 passed: ");
    print_split(split7);
    free_split(split7);

    printf("All tests passed!\n");
    return 0;
}
