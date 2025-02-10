#include "libft.h"
#include <ctype.h>
#include <stdio.h>

void test_isprint(int c)
{
    int output = ft_isprint(c);
    unsigned int original = isprint(c);
    
    printf("isprint   : %d\n", original);
    printf("ft_isprint: %d\n", output);
    
    if ((output == 0 && original != 0) || (output != 0 && original == 0)) {
        printf("❌ FAILURE ❌\n");
    } else {
        printf("✅ SUCCESS ✅\n");
    }
}

int main()
{
    test_isprint('A');  // Test uppercase letter
    test_isprint('z');  // Test lowercase letter
    test_isprint('0');  // Test digit
    test_isprint(' ');  // Test space character
    test_isprint('\n'); // Test newline character
    test_isprint('\0'); // Test null character
    test_isprint(31);   // Test non-printable control character (unit separator)
    test_isprint(32);   // Test first printable character (space)
    test_isprint(126);  // Test last printable character (~)
    test_isprint(127);  // Test DEL character
    test_isprint(128);  // Test out of range (above printable)

    return 0;
}

