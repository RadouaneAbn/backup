#include "libft.h"
#include <string.h>
#include <stdio.h>

void test_strlen(const char *s)
{
    size_t output = ft_strlen(s);
    size_t original = strlen(s);
    
    printf("strlen   : %zu\n", original);
    printf("ft_strlen: %zu\n", output);
    
    if (output != original) {
        printf("❌ FAILURE ❌\n");
    } else {
        printf("✅ SUCCESS ✅\n");
    }
}

int main()
{
    test_strlen("hello");          // Test regular string
    test_strlen("");               // Test empty string
    test_strlen("C programming");  // Test string with spaces
    test_strlen("12345");          // Test numeric string
    test_strlen("!@#$%^&*()");     // Test special characters
    test_strlen("longer string");  // Test longer string
    test_strlen("newline\n");      // Test string with newline
    test_strlen("\0");             // Test string with null character

    return 0;
}

