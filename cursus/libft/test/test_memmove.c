#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool compare_results(const char *expected, const char *actual, const char *test_case_name) {
    printf("%s:\n", test_case_name);
    printf("memmove   : %s\n", expected);
    printf("ft_memmove: %s\n", actual);

    if (strcmp(expected, actual) == 0) {
        printf("✅ SUCCESS\n\n");
        return true;
    } else {
        printf("❌ FAILURE\n\n");
        return false;
    }
}

void run_tests() {
    printf("Running all tests:\n\n");

    // 1. Basic non-overlapping test
    char src1[] = "Hello, World!";
    char dst1[20];
    char dst1_ft[20];

    memmove(dst1, src1, strlen(src1) + 1);
    ft_memmove(dst1_ft, src1, strlen(src1) + 1);
    compare_results(dst1, dst1_ft, "Basic non-overlapping test");

    // 2. Overlapping forward copy
    char str2[] = "abcdefgh";
    char str2_ft[] = "abcdefgh";
    memmove(str2 + 3, str2, 5);
    ft_memmove(str2_ft + 3, str2_ft, 5);
    compare_results(str2, str2_ft, "Overlapping forward copy");

    // 3. Overlapping backward copy
    char str3[] = "abcdefgh";
    char str3_ft[] = "abcdefgh";
    memmove(str3, str3 + 3, 5);
    ft_memmove(str3_ft, str3_ft + 3, 5);
    compare_results(str3, str3_ft, "Overlapping backward copy");

    // 4. Copying to the same memory
    char str4[] = "Hello, World!";
    char str4_ft[] = "Hello, World!";
    memmove(str4, str4, strlen(str4) + 1);
    ft_memmove(str4_ft, str4_ft, strlen(str4_ft) + 1);
    compare_results(str4, str4_ft, "Copying to the same memory");

    // 5. Zero length (nothing to copy)
    char src5[] = "Hello, World!";
    char dst5[20] = {0};
    char dst5_ft[20] = {0};
    memmove(dst5, src5, 0);
    ft_memmove(dst5_ft, src5, 0);
    compare_results(dst5, dst5_ft, "Zero length (nothing to copy)");

    // 6. Partial overlapping memory
    char str6[] = "123456789";
    char str6_ft[] = "123456789";
    memmove(str6 + 4, str6 + 2, 5);
    ft_memmove(str6_ft + 4, str6_ft + 2, 5);
    compare_results(str6, str6_ft, "Partial overlapping memory");

    // 7. Overlapping memory with different data types (int)
    int src7[] = {1, 2, 3, 4, 5};
    int dst7[5] = {0};
    int dst7_ft[5] = {0};
    memmove(dst7, src7, sizeof(int) * 5);
    ft_memmove(dst7_ft, src7, sizeof(int) * 5);
    printf("Overlapping memory with int test:\n");
    printf("memmove   : ");
    for (int i = 0; i < 5; i++) printf("%d ", dst7[i]);
    printf("\n");
    printf("ft_memmove: ");
    for (int i = 0; i < 5; i++) printf("%d ", dst7_ft[i]);
    printf("\n");
    for (int i = 0; i < 5; i++) {
        if (dst7[i] != dst7_ft[i]) {
            printf("❌ FAILURE\n\n");
            return;
        }
    }
    printf("✅ SUCCESS\n\n");
}

int main() {
    run_tests();
    return 0;
}
