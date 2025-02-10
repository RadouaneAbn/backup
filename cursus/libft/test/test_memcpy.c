#include "libft.h"
#include <string.h>
#include <stdio.h>

void test_memcpy(void *src, size_t n)
{
    // Store original state for comparison
    unsigned char original[100];
    unsigned char output[100];
    
    // Initialize dest arrays (for original and ft_memcpy)
    memset(original, 0, 100);
    memset(output, 0, 100);

    // Apply memcpy
    memcpy(original, src, n);
    ft_memcpy(output, src, n);
    
    // Output the results (printing first 10 bytes)
    printf("Original memcpy : ");
    for (size_t i = 0; i < 10; i++) {
        printf("%d ", original[i]);
    }
    printf("\n");

    printf("ft_memcpy       : ");
    for (size_t i = 0; i < 10; i++) {
        printf("%d ", output[i]);
    }
    printf("\n");

    // Compare results
    if (memcmp(original, output, 100) != 0) {
        printf("❌ FAILURE ❌\n");
    } else {
        printf("✅ SUCCESS ✅\n");
    }
}

int main()
{
    unsigned char src[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Initialize a source buffer with some values

    test_memcpy(src, 5);   // Test copying first 5 bytes
    test_memcpy(src, 10);  // Test copying all 10 bytes
    test_memcpy(src, 0);   // Test copying 0 bytes
    test_memcpy(src + 5, 5); // Test copying a slice (starting at src + 5)
    
    return 0;
}

