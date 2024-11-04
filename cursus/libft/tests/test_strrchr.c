#include "libft.h"
#include <string.h>
#include <stdio.h>

void test_strrchr(const char *s, int c)
{
    char *output = ft_strrchr(s, c);
    char *original = strrchr(s, c);
    
    printf("strrchr   : %s\n", original ? original : "NULL");
    printf("ft_strrchr: %s\n", output ? output : "NULL");
    if (!output && !original && output == original) {
        printf("✅ SUCCESS ✅\n");
        return ;
    }
    if (strcmp(output, original) != 0) {
        printf("❌ FAILURE ❌\n");
    } else {
        printf("✅ SUCCESS ✅\n");
    }
}

int main()
{
    test_strrchr("hello world", 'o');      // Test character present
    test_strrchr("hello world", 'h');      // Test first character
    test_strrchr("hello world", 'd');      // Test last character
    test_strrchr("hello world", 'x');      // Test character not present
    test_strrchr("", 'a');                  // Test empty string
    test_strrchr("hello world", '\0');     // Test null terminator

    return 0;
}

