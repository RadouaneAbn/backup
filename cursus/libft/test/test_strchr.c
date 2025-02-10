#include "libft.h"
#include <string.h>
#include <stdio.h>
#include <string.h>

void test_strchr(const char *s, int c)
{
    char *output = ft_strchr(s, c);
    char *original = strchr(s, c);
    
    printf("strchr   : %s\n", original ? original : "NULL");
    printf("ft_strchr: %s\n", output ? output : "NULL");
    if (!original && !output)
        return ;
    if (strcmp(output, original) != 0) {
        printf("❌ FAILURE ❌\n");
    } else {
        printf("✅ SUCCESS ✅\n");
    }
}

int main()
{
    test_strchr("hello world", 'o');      // Test character present
    test_strchr("hello world", 'h');      // Test first character
    test_strchr("hello world", 'd');      // Test last character
    test_strchr("hello world", 'x');      // Test character not present
    test_strchr("", 'a');                  // Test empty string
    test_strchr("hello world", '\0');     // Test null terminator

    return 0;
}

