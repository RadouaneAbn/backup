#include "libft.h"
#include <string.h>
#include <stdio.h>

void test_memset(void *s, int c, size_t n)
{
    // Store original state for comparison
    unsigned char original[100];
    unsigned char output[100];
    
    memcpy(original, s, 100);
    memcpy(output, s, 100);

    // Apply memset
    memset(original, c, n);
    ft_memset(output, c, n);
    
    // Output the results
    printf("Original memset: ");
    for (size_t i = 0; i < 10; i++) {
        printf("%d ", original[i]);
    }
    printf("\n");

    printf("ft_memset      : ");
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
    unsigned char buffer[100] = {0}; // Buffer initialized to zero

    test_memset(buffer, 'A', 10); // Test setting first 10 bytes to 'A'
    test_memset(buffer, 0, 10);    // Test setting first 10 bytes to 0
    test_memset(buffer, 'Z', 5);    // Test setting first 5 bytes to 'Z'
    test_memset(buffer, '*', 15);   // Test setting first 15 bytes to '*'
    
    return 0;
}

