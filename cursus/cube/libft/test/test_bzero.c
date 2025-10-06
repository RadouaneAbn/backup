#include "libft.h"
#include <string.h>
#include <stdio.h>

void test_bzero(void *s, size_t n)
{
    // Store original state for comparison
    unsigned char original[100];
    unsigned char output[100];
    
    // Copy initial buffer state for both original and ft_bzero tests
    memcpy(original, s, 100);
    memcpy(output, s, 100);

    // Apply bzero
    bzero(original, n);
    ft_bzero(output, n);
    
    // Output the results (printing first 10 bytes)
    printf("Original bzero  : ");
    for (size_t i = 0; i < 10; i++) {
        printf("%d ", original[i]);
    }
    printf("\n");

    printf("ft_bzero        : ");
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
    unsigned char buffer[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Initialize a buffer with some values

    test_bzero(buffer, 5);   // Test zeroing first 5 bytes
    test_bzero(buffer, 0);   // Test zeroing 0 bytes (no change)
    test_bzero(buffer, 10);  // Test zeroing all 10 bytes
    test_bzero(buffer, 100); // Test zeroing the entire buffer (100 bytes)
    
    return 0;
}

